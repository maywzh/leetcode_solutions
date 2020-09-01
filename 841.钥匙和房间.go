/*
 * @lc app=leetcode.cn id=841 lang=golang
 *
 * [841] 钥匙和房间
 */

// @lc code=start
var (
	num int
	vis []bool
)

func canVisitAllRooms(rooms [][]int) bool {
	n := len(rooms)
	num = 0
	vis = make([]bool, n)
	dfs(rooms, 0)
	return num == n
}

func dfs(rooms [][]int, key int) {
	if vis[key] {
		return
	} else {
		vis[key] = true
		num++
		for _, k := range rooms[key] {
			dfs(rooms, k)
		}
	}
}

// @lc code=end

