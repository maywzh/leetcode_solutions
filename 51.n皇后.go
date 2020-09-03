/*
 * @lc app=leetcode.cn id=51 lang=golang
 *
 * [51] N皇后
 */

// @lc code=start
func solveNQueens(n int) [][]string {
	type void struct{}
	var null void
	ans := make([][]string, 0)
	inArr := func(a int, list []int) bool {
		for _, b := range list {
			if b == a {
				return true
			}
		}
		return false
	}
	transform := func(queens []int) []string {
		rows := make([]string, 0)
		for i := 0; i < n; i++ {
			row := ""
			for j := 0; j < n; j++ {
				if queens[i] == j {
					row += "Q"
				} else {
					row += "."
				}
			}
			rows = append(rows, row)
		}
		return rows
	}

	var backtracing func([]int, map[int]void, map[int]void)
	backtracing = func(queens []int, xy_sum, xy_dif map[int]void) {
		l := len(queens)
		if l >= n {
			ans = append(ans, transform(queens))
			return
		}
		for i := 0; i < n; i++ {
			ok1 := inArr(i, queens)
			_, ok2 := xy_sum[l+i]
			_, ok3 := xy_dif[l-i]
			if !ok1 && !ok2 && !ok3 {
				xy_sum[l+i] = null
				xy_dif[l-i] = null
				backtracing(append(queens, i), xy_sum, xy_dif)
				delete(xy_sum, l+i)
				delete(xy_dif, l-i)
			}
		}
	}

	backtracing(make([]int, 0), make(map[int]void), make(map[int]void))
	return ans
}

// @lc code=end

