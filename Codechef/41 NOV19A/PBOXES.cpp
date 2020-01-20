#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int long long


#define ll long long
const ll N = 2e6+2;
vector <ll> tree(2 * N, 0);
void modify(ll p, ll value) {  // set value at position p
    for (tree[p += N] = value; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];
}
ll query(ll l, ll r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += tree[l++];
        if (r&1) res += tree[--r];
    }
    return res;
}

int block_size, NOB;
int P[200005], best_answer = -1e15, n;
int block_case_vals[2][500];
pair <int, int> block_answers_for_cases[2][500];

pair <int, pair <int, int> > case2_answers[500];
pair <int, int> maximum_in_block[500];
pair <int, int> minimum_in_block[500];
bool block_done[500];

vector <int> done(200007, 0);
set <int> done_pos[2];

int find_next(int i, bool x){
	auto pos = upper_bound(done_pos[x].begin(), done_pos[x].end(), i);
	if(pos != done_pos[x].end())
		return (*pos);
	return n;
}
set < pair < pair <int, int>, pair <int, pair <int, int> > > > Ranges;
set <pair < pair <int, pair <int, int> >, pair <int, int> > > Ranges_with_answer;

void range_delete(pair < pair <int, int>, pair <int, pair <int, int> > > i){
	pair < pair <int, pair <int, int> >, pair <int, int> > X = {i.second, i.first};
	Ranges.erase(i);
	Ranges_with_answer.erase(X);
}
pair <int, pair <int, int> >  partial(int l, int r){
	int case_vals = -1e16;
	pair <int, int> answers_for_cases;
	vector <pair <int, int> > minfromright(500, {1e16,-1});
	vector <pair <int, int> > maxfromleft(500, {-1e16, -1});

	for(int i = l; i <= r; i++){
		int j = i - l;
		if(!done[i])
			maxfromleft[j] = {P[i], i};
		if(j){
			if(maxfromleft[j].ff < maxfromleft[j-1].ff)
				maxfromleft[j] = maxfromleft[j-1];
		}
	}
	for(int i = r; i >= l; --i){
		int j = i - l;
		if(!done[i])
			minfromright[j] = {P[i], i};
		if(minfromright[j].ff > minfromright[j+1].ff)
			minfromright[j] = minfromright[j+1];	
	}
	for(int i = 0; i < r - l + 1; i++){
		if(maxfromleft[i].ff - minfromright[i+1].ff > case_vals){
			case_vals = maxfromleft[i].ff - minfromright[i+1].ff;
			answers_for_cases = {maxfromleft[i].ss, minfromright[i+1].ss};
		}
	}
	return make_pair(case_vals, answers_for_cases);
}
void update_block(int block_num){
	block_done[block_num] = 1;
	block_case_vals[1][block_num] = block_case_vals[0][block_num] = -1e16;
	maximum_in_block[block_num] = {-1e16,-1};
	minimum_in_block[block_num] = {1e16, -1};
	case2_answers[block_num] = {-1e16, {-1, -1}};
	vector <pair <int, int> > maxfromleft(500, {-1e16,-1}), minfromright(500, {1e16,-1});
	vector <pair <int, int> > minfromleft(500, {1e16,-1}), maxfromright(500, {-1e16,-1});

	for(int i = (block_num*block_size); i < min(n, (block_num+1)*block_size); i++){
		if(done[i] == 1){
			int cnt = -1;
			for(int j = i + 1; j < min(n, (block_num+1)*block_size); j++){
				if(done[j] == 1)
					cnt--;
				if(done[j] == 2)
					cnt++;
				if(cnt==0){
					case2_answers[block_num] = max(case2_answers[block_num], partial(i, j));
					i = j;
					break;
				}
			}
		}
	}
	for(int i = (block_num*block_size); i < min(n, (block_num+1)*block_size); i++){
		block_done[block_num] &= (done[i]!=0);
		int j = i - block_num*block_size;
		if(!done[i])
			minfromleft[j] = maxfromleft[j] = {P[i], i};
		if(j){
			if(maxfromleft[j].ff < maxfromleft[j-1].ff)
				maxfromleft[j] = maxfromleft[j-1];
			if(minfromleft[j].ff > minfromleft[j-1].ff)
				minfromleft[j] = minfromleft[j-1];
		}
	}
	for(int i = min(n, (block_num+1)*block_size) - 1; i >= (block_num*block_size); --i){
		int j = i - block_num*block_size;
		if(!done[i]){
			minfromright[j] = maxfromright[j] = {P[i], i};
		}
		if(maxfromright[j].ff < maxfromright[j+1].ff)
			maxfromright[j] = maxfromright[j+1];
		if(minfromright[j].ff > minfromright[j+1].ff)
			minfromright[j] = minfromright[j+1];	
	}
	maximum_in_block[block_num] = maxfromright[0];
	minimum_in_block[block_num] = minfromright[0];
	for(int i = 0; i < block_size - 1; i++){
		if(maxfromright[i+1].ff - minfromleft[i].ff > block_case_vals[0][block_num]){
			block_case_vals[0][block_num] = maxfromright[i+1].ff - minfromleft[i].ff;
			block_answers_for_cases[0][block_num] = {minfromleft[i].ss,maxfromright[i+1].ss};
		}
		if(maxfromleft[i].ff - minfromright[i+1].ff > block_case_vals[1][block_num]){
			block_case_vals[1][block_num] = maxfromleft[i].ff - minfromright[i+1].ff;
			block_answers_for_cases[1][block_num] = {maxfromleft[i].ss, minfromright[i+1].ss};
		}
	}
}
void update_ranges(int l, int r){
	if((l/block_size) == (r/block_size))return;
	int case_vals = -1e16;
	pair <int, int> answers_for_cases;

	vector <pair <int, int> > minfromright(500, {1e16,-1});
	vector <pair <int, int> > maxfromleft(500, {-1e16, -1});
	for(int i = 0; i < NOB; i++){
		if(i*block_size < l){
			if(min((i+1)*block_size, n) > l){
				pair <int, pair <int, int> > ansl = partial(l, min((i+1)*block_size - 1, r));
				// cout << l << ' ' << (i+1)*block_size - 1 << ' ' << r << '\n';
				if(ansl.first > case_vals){
					case_vals = ansl.first;
					answers_for_cases = ansl.second;
					// if(r == 7043){
					// 	cout << "dsgsgdfherhrdgrsg" << l << ' ' << r << ' ' << ansl.second.first << ' ' << ansl.second.second << '\n';
					// }
				}
				for(int j = l; j < min((i+1)*block_size, n); j++){
					if(!done[j]){
						if(P[j] > maxfromleft[i].ff)
							maxfromleft[i] = {P[j], j};
					}
				}
			}
			continue;
		}
		if(min((i+1)*block_size - 1, n) > r){
			if(((r+1)%block_size)){
				pair <int, pair <int, int> > ansl = partial(max(i*block_size, l), r);
				if(ansl.first > case_vals){
					case_vals = ansl.first;
					answers_for_cases = ansl.second;
				}
				for(int j = (r/block_size)*block_size; j < r; j++){
					if(!done[j]){
						if(P[j] > maxfromleft[i].ff)
							maxfromleft[i] = {P[j], j};
					}
					if(i)
						if(maxfromleft[i].ff < maxfromleft[i-1].ff)
							maxfromleft[i] = maxfromleft[i-1];
				}
			}
			break;
		}
		if(case_vals < block_case_vals[1][i]){
			case_vals = block_case_vals[1][i];
			answers_for_cases = block_answers_for_cases[1][i];
		}
		if(!block_done[i])
			maxfromleft[i] = maximum_in_block[i];
		if(i)
			if(maxfromleft[i].ff < maxfromleft[i-1].ff)
				maxfromleft[i] = maxfromleft[i-1];
	}
	for(int i = NOB - 1; i >= 0; --i){
		if(((i+1)*block_size) - 1 > r){
			if(i*block_size <= r){
				minfromright[i] = {1e16, -1};
				for(int j = r - 1; j >= (r/block_size)*block_size; j--){
					if(!done[j]){
						if(P[j] < minfromright[i].ff)
							minfromright[i] = {P[j], j};
					}
				}
			}
			continue;
		}
		if(i*block_size < l){
			if((i+1)*block_size > l){
				minfromright[i] = {1e16, -1};
				for(int j = (i+1)*block_size - 1; j >= (r/block_size)*block_size; j--){
					if(!done[j]){
						if(P[j] < minfromright[i].ff)
							minfromright[i] = {P[j], j};
					}
				}
				if(i!=NOB-1)
					if(minfromright[i].ff > minfromright[i+1].ff)
						minfromright[i] = minfromright[i+1];
			}
			break;
		}
		if(!block_done[i])
			minfromright[i] = minimum_in_block[i];
		if(i!=NOB-1)
			if(minfromright[i].ff > minfromright[i+1].ff)
				minfromright[i] = minfromright[i+1];
	}
	for(int i = 0; i < NOB-1; i++){
		if(maxfromleft[i].ff - minfromright[i+1].ff > case_vals){
			case_vals = maxfromleft[i].ff - minfromright[i+1].ff;
			answers_for_cases = {maxfromleft[i].ss,minfromright[i+1].ss};
		}
	}

	Ranges.insert({{l, r}, {case_vals, answers_for_cases}});
	Ranges_with_answer.insert({{case_vals, answers_for_cases},{l, r}});
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	memset(block_done, 0, sizeof(block_done));
	vector <pair <int, int> > a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].ff >> a[i].ss;
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; i++)
		P[i] = a[i].ss;

	block_size = min((int)sqrt(n) + 1, n);
	NOB = (n/block_size) + ((n%block_size)>0);
	for(int i = 0; i < NOB; i++){
		update_block(i);
	}
	int kk;
	for( kk = 0; kk < n/2; kk++){
		if(kk == 40000)return 0;
		vector <int> case_vals(2, -1e16);
		vector <pair <int, int> > answers_for_cases(2);
		for(int i = 0; i < NOB; i++){
			if(case_vals[0] < block_case_vals[0][i]){
				case_vals[0] = block_case_vals[0][i];
				answers_for_cases[0] = block_answers_for_cases[0][i];
			}
			if(case_vals[1] < case2_answers[i].ff){
				case_vals[1] = case2_answers[i].ff;
				answers_for_cases[1] = case2_answers[i].ss;
			}
		}
		// cout << answers_for_cases[0].ss << ' ' << answers_for_cases[0].ff << '\n';

		vector <pair <int, int> > maxfromright(500, {-1e16,-1});
		vector <pair <int, int> > minfromleft(500, {1e16, -1});
		for(int i = 0; i < NOB; i++){
			// cout << minimum_in_block[i].ff << '\n';
			if(!block_done[i])
				minfromleft[i] = minimum_in_block[i];
			if(i)
				if(minfromleft[i].ff > minfromleft[i-1].ff)
					minfromleft[i] = minfromleft[i-1];
		}
		for(int i = NOB - 1; i >= 0; --i){
			if(!block_done[i])
				maxfromright[i] = maximum_in_block[i];
			if(i!=NOB-1)
				if(maxfromright[i].ff < maxfromright[i+1].ff)
					maxfromright[i] = maxfromright[i+1];
		}
		for(int i = 0; i < NOB-1; i++){
			if(maxfromright[i+1].ff - minfromleft[i].ff > case_vals[0]){
				case_vals[0] = maxfromright[i+1].ff - minfromleft[i].ff;
				answers_for_cases[0] = {minfromleft[i].ss,maxfromright[i+1].ss};
			}
		}
		if(Ranges.size()){
			auto biggest = Ranges_with_answer.end();
			biggest--;
			case_vals[1] = (biggest->first).first;
			answers_for_cases[1] = (biggest->first).second;
			// cout << "Largest " << case_vals[1] << ' ' << answers_for_cases[1].ff << ' ' << answers_for_cases[1].ss << ' ' << (biggest->second).first << ' ' << (biggest->second).ss << '\n';
		}
		// cout << "Ranges\n";
		// for(auto it:Ranges){
		// 	cout << it.ff.ff << ' ' << it.ff.ss << '\n';
		// }
		int best_case = max_element(case_vals.begin(), case_vals.end()) - case_vals.begin();
		if(case_vals[0] == case_vals[1])
			best_case = 1;
		int u = answers_for_cases[best_case].ff, v = answers_for_cases[best_case].ss;
		if(best_case == 1){
			// cout <<"u and v                                " <<  u << ' ' << v << '\n';
			done[u] = 2;
			done[v] = 1;
			done_pos[0].insert(v);
			done_pos[1].insert(u);
			modify(u, 1);
			modify(v, -1);
			update_block(u/block_size);
			if((u/block_size) != (v/block_size))
				update_block(v/block_size);
			// split the range
			auto IT = Ranges.lower_bound({{u, 1e9}, {0,{0,0}}});
			IT--;
			int l = (IT -> first).first;
			int r = (IT -> first).second;
			range_delete(*IT);
			int cur = query(l, u);
			for(int i = u; i <= r; i++){
				if(done[i] == 2)
					cur++;
				if(done[i] == 1)
					cur--;
				if(cur == 0){
					u = i;
					break;
				}
			}
			cur = 0;
			for(int i = r; i > 0; i--){
				if(done[i] == 2)
					cur++;
				if(done[i] == 1)
					cur--;
				if(cur == 0){
					v = i;
					break;
				}
			}
			if(v < l){
				l = v;
				u = r;
			}
			update_ranges(l, u);
			if(v > u){
				for(int i = u + 1; i < v; i++){
					if(done[i] == 1){
						int cnt = -1;
						for(int j = i + 1; j < v; j++){
							if(done[j] == 1)
								cnt--;
							if(done[j] == 2)
								cnt++;
							if(cnt==0){
								update_ranges(i, j);
								i = j;
								break;
							}
						}
					}
				}
				if(v > u){
					update_ranges(v, r);
					int u2 = -1, v2 = -1;
					for(int i = u + 1; i < v; i++){
						if(done[i] == 1){
							int cnt = -1;
							for(int j = i + 1; j < v; j++){
								if(done[j] == 1)
									cnt--;
								if(done[j] == 2)
									cnt++;
								if(cnt==0){
									update_ranges(i, j);
									i = j;
									break;
								}
							}
						}
					}
				}
			}
		}
		if(best_case == 0){
			done[u] = 1;
			done[v] = 2;
			done_pos[1].insert(v);
			done_pos[0].insert(u);
			modify(u, -1);
			modify(v, 1);
			update_block(u/block_size);
			if((u/block_size) != (v/block_size))
				update_block(v/block_size);
			int l = u, r = v;
			while(Ranges.size()){
				auto IT = Ranges.lower_bound({{l, 1e9}, {0,{0,0}}});
				if(IT!=Ranges.begin())
					IT--;
				int u2 = (IT->ff).ff, v2 = (IT->ff).ss;
				if(u2 > r||l > v2)
					IT++;
				if(IT == Ranges.end())
					break;
				u2 = (IT->ff).ff;
				v2 = (IT->ff).ss;
				if(u2 > r||l > v2)
					break;
				l = min(l, u2);
				r = max(r, v2);
				range_delete(*IT);
			}

			for(int i = (l/block_size)*block_size; i < l; i++){
				if(done[i] == 1){
					int cnt = -1;
					for(int j = i + 1; j < ((l/block_size) + 1)*block_size; j++){
						if(done[j] == 1)
							cnt--;
						if(done[j] == 2)
							cnt++;
						if(cnt==0){
							if(j>=l){
								l = i;
							}
							i = j;
							break;
						}
					}
				}
			}
			for(int i = (r/block_size)*block_size; i < r; i++){
				if(done[i] == 1){
					int cnt = -1;
					for(int j = i + 1; j < ((r/block_size) + 1)*block_size; j++){
						if(done[j] == 1)
							cnt--;
						if(done[j] == 2)
							cnt++;
						if(cnt==0){
							if(j>=r){
								r = j;
							}
							i = j;
							break;
						}
					}
				}
			}
			update_ranges(l, r);
		}
		ans += case_vals[best_case];
		// cout << best_case << ' ' << ans << '\n';
		if(best_answer > ans)
			break;
		best_answer = max(best_answer, ans);
		cout << best_answer << '\n';
	}
	while(kk < n/2){
		cout << best_answer << '\n';
		kk++;
	}
	return 0;
}