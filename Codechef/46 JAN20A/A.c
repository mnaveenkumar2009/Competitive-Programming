#include <stdio.h>

#define max(l, r) (((l) > (r)? (l):(r)))
#define min(l, r) (((l) > (r)? (l):(r)))

signed main(){
	int n, q;
	scanf("%d%d", &n, &q);

	int block_size = 700;

	int NOB = (n/block_size) + ((n % block_size) > 0);
	int N = NOB * block_size;

	int For_mini[2*N +2], For_maxi[2*N + 2];
	int For_mini_tim[2*N +2], For_maxi_tim[2*N + 2];
	memset(For_maxi_tim, -1, sizeof(For_maxi_tim));
	memset(For_mini_tim, -1, sizeof(For_mini_tim));

	int time_for_maxmin = 0;
	int p[N];
	for(int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for(int i = n; i < N; i++)
		p[i] = 1e9;

	int dp_from_left[N][NOB], dp_from_right[N][NOB];
	int dp[N][block_size];
	int block_maximum[NOB][NOB], block_minimum[NOB][NOB];
	
	for(int block = 0; block < NOB; block++){
		int end_block = (block + 1) * block_size;
		int start_block = block * block_size;
		for(int i = start_block; i < end_block; i++){
			int maxi = p[i], mini = p[i];
			for(int j = i; j < end_block; j++){
				if(maxi < p[j])
					maxi = p[j];
				else
					if(mini > p[j])
						mini = p[j];
				if(maxi - mini == j - i)
					dp[i][j - i] = j - i + 1;
				else
					dp[i][j - i] = dp[i][j - i - 1];
			}
			if(i == start_block){
				block_maximum[block][block] = maxi;
				block_minimum[block][block] = mini;
			}
		}
		for(int i = end_block - 2; i >= start_block; i--){
			for(int j = i + 1; j < end_block; j++){
				dp[i][j - i] = max(dp[i][j - i], dp[i+1][j - i - 1]);
			}
		}
		for(int i = start_block; i < end_block; i++){
			dp_from_left[i][block] = dp[i][end_block - 1 - i];
			dp_from_right[i][block] = dp[start_block][i - start_block];
		}
	}
	for(int block = 0; block < NOB; block++){
		for(int block2 = block + 1; block2 < NOB; block2++){
			block_maximum[block][block2] = max(block_maximum[block][block2 - 1], block_maximum[block2][block2]);
			block_minimum[block][block2] = min(block_minimum[block][block2 - 1], block_minimum[block2][block2]);
		}
	}
	
	for(int iter_block_size = 1; iter_block_size < NOB; iter_block_size++){
		for(int block = 0; block < NOB - iter_block_size; block++){
			// block to block + iter_block_size
			int l = block * block_size, r = (block + iter_block_size + 1) * block_size - 1;
			int block_end_l = (l/block_size + 1) * block_size - 1, block_start_r = (r/block_size) * block_size;
			
			int ans = dp_from_right[r][l/block_size + 1];
			int maxi = 0, mini = 1e9;
			if(block_end_l != block_start_r - 1){
				maxi = block_maximum[l/block_size + 1][r/block_size - 1];
				mini = block_minimum[l/block_size + 1][r/block_size - 1];
			}
			int cur_min_pos = block_start_r - 1, cur_max_pos = block_start_r - 1;
			int temp_min = mini, temp_max = maxi;
			time_for_maxmin++;
			for(int i = block_end_l; i >= l; i--){
				ans = max(dp_from_left[i][(r/block_size) - 1], ans);
				maxi = max(maxi, p[i]);
				mini = min(mini, p[i]);
				temp_min = min(temp_min, mini);
				temp_max = max(temp_max, maxi);
				while(cur_min_pos != r){
					if(p[cur_min_pos + 1] > mini){
						cur_min_pos++;
						temp_max = max(temp_max, p[cur_min_pos]);
						if(temp_max > maxi && temp_max < 1e9){
							For_mini[cur_min_pos - temp_max + N] = cur_min_pos;
							For_mini_tim[cur_min_pos - temp_max + N] = time_for_maxmin;
						}
					}
					else
						break;
				}
				while(cur_max_pos != r){
					if(p[cur_max_pos + 1] < maxi){
						cur_max_pos++;
						temp_min = min(temp_min, p[cur_max_pos]);
						if(temp_min < mini && temp_min < 1e9){
							For_maxi[cur_max_pos + temp_min] = cur_max_pos;
							For_maxi_tim[cur_max_pos + temp_min] = time_for_maxmin;
						}
					}
					else
						break;
				}
				if((i + maxi - mini) <= min(cur_min_pos, cur_max_pos)){
					ans = max(ans, maxi - mini + 1);
					dp_from_right[i + (maxi - mini)][block] = max(dp_from_right[i + (maxi - mini)][block], maxi - mini + 1);
				}
				if(i - mini + N <= 2*N){
					int F_min = For_mini[i - mini + N];
					if(F_min > cur_max_pos && For_mini_tim[i - mini + N] == time_for_maxmin)
						ans = max(ans, F_min - i + 1);
				}
				if(i + maxi <= 2*N){
					int F_max = For_maxi[i + maxi];
					if(F_max > cur_min_pos && For_maxi_tim[i + maxi] == time_for_maxmin)
						ans = max(ans, F_max - i + 1);
				}
				dp_from_left[i][block + iter_block_size] = max(dp_from_left[i][block + iter_block_size], ans);
			}
			time_for_maxmin++;

			// maxi = 0, mini = 1e9;
			// if(block_end_l != block_start_r - 1){
			// 	maxi = block_maximum[l/block_size + 1][r/block_size - 1];
			// 	mini = block_minimum[l/block_size + 1][r/block_size - 1];
			// }
			// cur_min_pos = block_end_l + 1;
			// cur_max_pos = block_end_l + 1;
			// ans = dp_from_left[l][(r/block_size) - 1];
			// temp_max = maxi;
			// temp_min = mini;
			// for(int i = block_start_r; i <= r; i++){	
			// 	ans = max(ans, dp_from_right[i][l/block_size + 1]);
			// 	maxi = max(maxi, p[i]);
			// 	mini = min(mini, p[i]);
			// 	temp_min = min(temp_min, mini);
			// 	temp_max = max(temp_max, maxi);
			// 	while(cur_min_pos != l){
			// 		if(p[cur_min_pos - 1] > mini){
			// 			cur_min_pos--;
			// 			temp_max = max(temp_max, p[cur_min_pos]);
			// 			if(temp_max > maxi && temp_max < 1e9){
			// 				For_mini[cur_min_pos + temp_max] = cur_min_pos + 1;
			// 				For_mini_tim[cur_min_pos + temp_max] = time_for_maxmin;
			// 			}
			// 		}
			// 		else
			// 			break;
			// 	}
			// 	while(cur_max_pos != l){
			// 		if(p[cur_max_pos - 1] < maxi){
			// 			cur_max_pos--;
			// 			temp_min = min(temp_min, p[cur_max_pos]);
			// 			if(temp_min < mini && temp_min < 1e9){
			// 				For_maxi[cur_max_pos - temp_min + N] = cur_max_pos + 1;
			// 				For_maxi_tim[cur_max_pos - temp_min + N] = time_for_maxmin;
			// 			}
			// 		}
			// 		else
			// 			break;
			// 	}
			// 	if(i - (maxi - mini) >= max(cur_min_pos, cur_max_pos)){
			// 		ans = max(ans, maxi - mini + 1);
			// 		dp_from_left[i - (maxi - mini)][block + iter_block_size] = max(dp_from_left[i - (maxi - mini)][block + iter_block_size], maxi - mini + 1);
			// 	}
			// 	if(i + mini <= 2*N){
			// 		int F_min = For_mini[i + mini] - 1;
			// 		if(F_min < cur_max_pos && F_min != -1 && For_mini_tim[i + mini] == time_for_maxmin)
			// 			ans = max(ans, i - F_min + 1);
			// 	}
			// 	if( i - maxi + N <= 2* N){
			// 		int F_max = For_maxi[i - maxi + N] - 1;
			// 		if(F_max < cur_min_pos && F_max != -1 && For_maxi_tim[i - maxi + N] == time_for_maxmin)
			// 			ans = max(ans, i - F_max + 1);
			// 	}
			// 	dp_from_right[i][block] = max(dp_from_right[i][block], ans);
			// }
			// for(int i = block_start_r + 1; i <= r; i++)
			// 	dp_from_right[i][block] = max(dp_from_right[i][block], dp_from_right[i - 1][block]);
			// for(int i = block_end_l - 1; i >= l; i--)
			// 	dp_from_left[i][block + iter_block_size] = max(dp_from_left[i][block + iter_block_size], dp_from_left[i + 1][block + iter_block_size]);
		}
	}
	int ans = 0;
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		l = (l + ans - 1) % n;
		r = (r + ans - 1) % n;
		if(l > r){
			l = l + r;
			r = l - r;
			l = l - r;
		}
		if(l/block_size == r/block_size){
			printf("%d\n", (ans = dp[l][r - l]));
		}
		else{
			// time_for_maxmin++;
			// // O(block_size)
			// ans = max(dp_from_left[l][(r/block_size) - 1], dp_from_right[r][l/block_size + 1]);
			// int block_end_l = (l/block_size + 1) * block_size - 1, block_start_r = (r/block_size) * block_size;

			// // below 2 lines are useless
			// ans = max(dp[l][block_end_l - l], ans);
			// ans = max(dp[block_start_r][r - block_start_r], ans);
			
			// int maxi = 0, mini = 1e9;
			// if(block_end_l != block_start_r - 1){
			// 	maxi = block_maximum[l/block_size + 1][r/block_size - 1];
			// 	mini = block_minimum[l/block_size + 1][r/block_size - 1];
			// }
			// int cur_min_pos = block_start_r - 1, cur_max_pos = block_start_r - 1;
			// int temp_min = mini, temp_max = maxi;
			// for(int i = block_end_l; i >= l; i--){
			// 	maxi = max(maxi, p[i]);
			// 	mini = min(mini, p[i]);
			// 	temp_min = min(temp_min, mini);
			// 	temp_max = max(temp_max, maxi);
				
			// 	while(cur_min_pos != r){
			// 		if(p[cur_min_pos + 1] > mini){
			// 			cur_min_pos++;
			// 			temp_max = max(temp_max, p[cur_min_pos]);
			// 			if(temp_max > maxi){
			// 				For_mini[cur_min_pos - temp_max + N] = cur_min_pos;
			// 				For_mini_tim[cur_min_pos - temp_max + N] = time_for_maxmin;
			// 			}
			// 		}
			// 		else
			// 			break;
			// 	}
			// 	while(cur_max_pos != r){
			// 		if(p[cur_max_pos + 1] < maxi){
			// 			cur_max_pos++;
			// 			temp_min = min(temp_min, p[cur_max_pos]);
			// 			if(temp_min < mini){
			// 				For_maxi[cur_max_pos + temp_min] = cur_max_pos;
			// 				For_maxi_tim[cur_max_pos + temp_min] = time_for_maxmin;
			// 			}
			// 		}
			// 		else
			// 			break;
			// 	}
			// 	if(i + maxi - mini <= min(cur_min_pos, cur_max_pos)){
			// 		ans = max(ans, maxi - mini + 1);
			// 	}
			// 	int F_min = For_mini[i - mini + N];
			// 	if(F_min > cur_max_pos && For_mini_tim[i - mini + N] == time_for_maxmin){
			// 		ans = max(ans, F_min - i + 1);
			// 	}
			// 	int F_max = For_maxi[i + maxi];
			// 	if(F_max > cur_min_pos && For_maxi_tim[i + maxi] == time_for_maxmin){
			// 		ans = max(ans, F_max - i + 1);
			// 	}
			// }
			// maxi = 0, mini = 1e9;
			// if(block_end_l != block_start_r - 1){
			// 	maxi = block_maximum[l/block_size + 1][r/block_size - 1];
			// 	mini = block_minimum[l/block_size + 1][r/block_size - 1];
			// }
			// cur_min_pos = block_end_l + 1;
			// cur_max_pos = block_end_l + 1;

			// for(int i = block_start_r; i <= r; i++){
			// 	maxi = max(maxi, p[i]);
			// 	mini = min(mini, p[i]);
			// 	while(cur_min_pos != l){
			// 		if(p[cur_min_pos - 1] > mini)
			// 			cur_min_pos--;
			// 		else
			// 			break;
			// 	}
			// 	while(cur_max_pos != l){
			// 		if(p[cur_max_pos - 1] < maxi)
			// 			cur_max_pos--;
			// 		else
			// 			break;
			// 	}
			// 	if(i - maxi + mini >= max(cur_min_pos, cur_max_pos))
			// 		ans = max(ans, maxi - mini + 1);
			// }
			printf("%d\n", ans);
		}
	}
}