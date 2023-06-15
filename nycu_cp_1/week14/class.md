# Problem E
given a tree with n points (1 ~ n)

x -> y if y > x

找任一組 x -> y 的 path length 總和

1 -> (n-1) 種
2 -> floor(n/2)
...



## Depth First Search
* 給定 DFS 進入和離開所有點的時間，是否可以反推回 tree?




## LCA
### 倍增法 -> 必考
sparse table: 求出 min(ai, ai+1, ai+2, ..., ai+k)

先記錄所有點的 n 代祖先 (nxn matrix) => 需要空間太大
如果兩個點的深度一樣，那麼就一定是從 1 代到 n 代第一次兩點祖先相同。





# recall "tree" but not tree
* segment tree -> range sum, range change -> 必考
* fenwick tree

# 期末考
* DP: 三題
* segment tree
* LCA 倍增法
* convex hull 一題
* 其他計算幾何: 一題
* DAG 和 LAG 會考!



https://shawnliang.wiki/post/lca-binary-lifting/