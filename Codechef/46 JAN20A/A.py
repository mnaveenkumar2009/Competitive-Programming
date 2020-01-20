import numpy as np
n, q = map(int, input().split())

block_size = 5000

NOB = int((n / block_size) + ((n % block_size) > 0))

N = NOB * block_size;
p = (list(map(int, input().split())))
while(len(p) != N):
	p.append(int(1e9))
p = np.array(p)

dp = np.int32(np.zeros((N, block_size)))
dp_from_left = np.int32(np.zeros((N, NOB)))
dp_from_right = np.int32(np.zeros((N, NOB)))
block_minimum = np.int32(np.zeros((NOB, NOB)))
block_maximum = np.int32(np.zeros((NOB, NOB)))

for block in range(NOB):
	end_block = (block + 1) * block_size;
	start_block = block * block_size;
	for i in range(start_block, end_block):
		maxi = p[i]
		mini = p[i]
		for j in range(i, end_block):
			if(maxi < p[j]):
				maxi = p[j]
			else:
				if(mini > p[j]):
					mini = p[j]
			if(maxi - mini == j - i):
				dp[i][j - i] = j - i + 1
			else:
				dp[i][j - i] = dp[i][j - i - 1]
		if(i == start_block):
			block_maximum[block][block] = maxi
			block_minimum[block][block] = mini
	for i in range(end_block - 2, start_block - 1, -1):
		for j in range(i + 1, end_block):
			dp[i][j - i] = max(dp[i][j - i], dp[i+1][j - i - 1])
	for i in range(start_block, end_block):
		dp_from_left[i][block] = dp[i][end_block - 1 - i]
		dp_from_right[i][block] = dp[start_block][i - start_block]
for block in range(NOB):
	for block2 in range(block + 1, NOB):
		block_maximum[block][block2] = max(block_maximum[block][block2 - 1], block_maximum[block2][block2]);
		block_minimum[block][block2] = min(block_minimum[block][block2 - 1], block_minimum[block2][block2]);
print("hi")
for iter_block_size in range(1,NOB):
	for block in range(NOB - iter_block_size):
		l = block * block_size
		r = (block + iter_block_size + 1) * block_size - 1
		block_end_l = (l/block_size + 1) * block_size - 1
		block_start_r = (r/block_size) * block_size;
		ans = dp_from_right[r][l/block_size + 1];
		maxi = 0
		mini = int(1e9)
		if(block_end_l != block_start_r - 1):
			maxi = block_maximum[l/block_size + 1][r/block_size - 1]
			mini = block_minimum[l/block_size + 1][r/block_size - 1]
		cur_min_pos = block_start_r - 1
		cur_max_pos = block_start_r - 1
		For_mini = {}
		For_maxi = {}
# 		vector <int> For_mini(2 * N + 2, 0), For_maxi(2 * N + 2, 0);
		temp_min = mini
		temp_max = maxi
		for i in range(block_end_l, l - 1, -1):
			ans = max(dp_from_left[i][(r/block_size) - 1], ans)
			maxi = max(maxi, p[i]);
			mini = min(mini, p[i]);
			temp_min = min(temp_min, mini);
			temp_max = max(temp_max, maxi);
			while(cur_min_pos != r):
				if(p[cur_min_pos + 1] > mini):
					cur_min_pos += 1
					temp_max = max(temp_max, p[cur_min_pos])
					if(temp_max > maxi and temp_max < 1e9):
						For_mini[cur_min_pos - temp_max + N] = cur_min_pos;
				else:
					break
			while(cur_max_pos != r):
				if(p[cur_max_pos + 1] < maxi):
					cur_max_pos += 1
					temp_min = min(temp_min, p[cur_max_pos])
					if(temp_min < mini and temp_min < 1e9):
						For_maxi[cur_max_pos + temp_min] = cur_max_pos;
				else:
					break;
			if i + maxi - mini <= min(cur_min_pos, cur_max_pos):
				ans = max(ans, maxi - mini + 1);
				dp_from_right[i + (maxi - mini)][block] = max(dp_from_right[i + (maxi - mini)][block], maxi - mini + 1);
			F_min = For_mini[i - mini + N];
# 			if(F_min > cur_max_pos)
# 				ans = max(ans, F_min - i + 1);
# 			int F_max = For_maxi[i + maxi];
# 			if(F_max > cur_min_pos)
# 				ans = max(ans, F_max - i + 1);
# 			dp_from_left[i][block + iter_block_size] = max(dp_from_left[i][block + iter_block_size], ans);
# 		}

# 		maxi = 0, mini = 1e9;
# 		if(block_end_l != block_start_r - 1){
# 			maxi = block_maximum[l/block_size + 1][r/block_size - 1];
# 			mini = block_minimum[l/block_size + 1][r/block_size - 1];
# 		}
# 		cur_min_pos = block_end_l + 1;
# 		cur_max_pos = block_end_l + 1;
# 		vector <int> For_mini2(2 * N + 2, 0), For_maxi2(2 * N + 2, 0);
# 		ans = dp_from_left[l][(r/block_size) - 1];
# 		temp_max = maxi;
# 		temp_min = mini;
# 		for(int i = block_start_r; i <= r; i++){	
# 			ans = max(ans, dp_from_right[i][l/block_size + 1]);
# 			maxi = max(maxi, p[i]);
# 			mini = min(mini, p[i]);
# 			temp_min = min(temp_min, mini);
# 			temp_max = max(temp_max, maxi);
# 			while(cur_min_pos != l){
# 				if(p[cur_min_pos - 1] > mini){
# 					cur_min_pos--;
# 					temp_max = max(temp_max, p[cur_min_pos]);
# 					if(temp_max > maxi && temp_max < 1e9)
# 						For_mini2[cur_min_pos + temp_max] = cur_min_pos + 1;
# 				}
# 				else
# 					break;
# 			}
# 			while(cur_max_pos != l){
# 				if(p[cur_max_pos - 1] < maxi){
# 					cur_max_pos--;
# 					temp_min = min(temp_min, p[cur_max_pos]);
# 					if(temp_min < mini && temp_min < 1e9){
# 						For_maxi2[cur_max_pos - temp_min + N] = cur_max_pos + 1;
# 					}
# 				}
# 				else
# 					break;
# 			}
# 			if(i - (maxi - mini) >= max(cur_min_pos, cur_max_pos)){
# 				ans = max(ans, maxi - mini + 1);
# 				dp_from_left[i - (maxi - mini)][block + iter_block_size] = max(dp_from_left[i - (maxi - mini)][block + iter_block_size], maxi - mini + 1);
# 			}
# 			int F_min = For_mini2[i + mini] - 1;
# 			if(F_min < cur_max_pos && F_min != -1)
# 				ans = max(ans, i - F_min + 1);
# 			int F_max = For_maxi2[i - maxi + N] - 1;
# 			if(F_max < cur_min_pos && F_max != -1)
# 				ans = max(ans, i - F_max + 1);
# 			dp_from_right[i][block] = max(dp_from_right[i][block], ans);
# 		}
# 		for(int i = block_start_r + 1; i <= r; i++){
# 			dp_from_right[i][block] = max(dp_from_right[i][block], dp_from_right[i - 1][block]);
# 		}
# 		for(int i = block_end_l - 1; i >= l; i--){
# 			dp_from_left[i][block + iter_block_size] = max(dp_from_left[i][block + iter_block_size], dp_from_left[i + 1][block + iter_block_size]);
# 		}
# 	}
# }

ans = 0
while (q>0):
	q -= 1
	l, r = map(int, input().split())
	l = (l + ans - 1) % n;
	r = (r + ans - 1) % n;
	if(l > r):
		l = l + r
		r = l - r
		l = l - r
	if int(l/block_size) == int(r/block_size):
		ans = dp[l][r - l]
		print(ans)
# 	else{
# 		// O(block_size)
# 		ans = max(dp_from_left[l][(r/block_size) - 1], dp_from_right[r][l/block_size + 1]);
# 		int block_end_l = (l/block_size + 1) * block_size - 1, block_start_r = (r/block_size) * block_size;

# 		// below 2 lines are useless
# 		ans = max(dp[l][block_end_l - l], ans);
# 		ans = max(dp[block_start_r][r - block_start_r], ans);
	
# 		int maxi = 0, mini = 1e9;
# 		if(block_end_l != block_start_r - 1){
# 			maxi = block_maximum[l/block_size + 1][r/block_size - 1];
# 			mini = block_minimum[l/block_size + 1][r/block_size - 1];
# 		}
# 		int cur_min_pos = block_start_r - 1, cur_max_pos = block_start_r - 1;
# 		vector <int> For_mini(2*N +2, 0), For_maxi(2*N + 2, 0);
# 		int temp_min = mini, temp_max = maxi;
# 		// cout << "max and min" << maxi << ' ' << mini  << '\n';
# 		// cout << "cur_min_pos, max" << cur_min_pos << ' ' << cur_max_pos  << '\n';
# 		for(int i = block_end_l; i >= l; i--){
# 			maxi = max(maxi, p[i]);
# 			mini = min(mini, p[i]);
# 			temp_min = min(temp_min, mini);
# 			temp_max = max(temp_max, maxi);
# 			// maxi - mini = x - i
# 			// maxi + i = x + mini
# 			// i - mini = x - maxi
# 			while(cur_min_pos != r){
# 				if(p[cur_min_pos + 1] > mini){
# 					cur_min_pos++;
# 					temp_max = max(temp_max, p[cur_min_pos]);
# 					if(temp_max > maxi){
# 						For_mini[cur_min_pos - temp_max + N] = cur_min_pos;
# 					}
# 				}
# 				else
# 					break;
# 			}
# 			while(cur_max_pos != r){
# 				if(p[cur_max_pos + 1] < maxi){
# 					cur_max_pos++;
# 					temp_min = min(temp_min, p[cur_max_pos]);
# 					if(temp_min < mini){
# 						For_maxi[cur_max_pos + temp_min] = cur_max_pos;
# 					}
# 				}
# 				else
# 					break;
# 			}
# 			// cout << mini << ' ' << maxi << ' ' << cur_min_pos << ' ' << cur_max_pos << '\n';
# 			if(i + maxi - mini <= min(cur_min_pos, cur_max_pos)){
# 				ans = max(ans, maxi - mini + 1);
# 			}
# 			int F_min = For_mini[i - mini + N];
# 			if(F_min > cur_max_pos){
# 				ans = max(ans, F_min - i + 1);
# 			}
# 			int F_max = For_maxi[i + maxi];
# 			if(F_max > cur_min_pos){
# 				ans = max(ans, F_max - i + 1);
# 			}
# 			// cout << F_max << ' ' << F_min << '\n';
# 		}
# 		maxi = 0, mini = 1e9;
# 		if(block_end_l != block_start_r - 1){
# 			maxi = block_maximum[l/block_size + 1][r/block_size - 1];
# 			mini = block_minimum[l/block_size + 1][r/block_size - 1];
# 		}
# 		cur_min_pos = block_end_l + 1;
# 		cur_max_pos = block_end_l + 1;

# 		for(int i = block_start_r; i <= r; i++){
# 			maxi = max(maxi, p[i]);
# 			mini = min(mini, p[i]);
# 			while(cur_min_pos != l){
# 				if(p[cur_min_pos - 1] > mini)
# 					cur_min_pos--;
# 				else
# 					break;
# 			}
# 			while(cur_max_pos != l){
# 				if(p[cur_max_pos - 1] < maxi)
# 					cur_max_pos--;
# 				else
# 					break;
# 			}
# 			if(i - maxi + mini >= max(cur_min_pos, cur_max_pos))
# 				ans = max(ans, maxi - mini + 1);
# 		}
# 		cout << ans << '\n';
# 	}
# }
# }