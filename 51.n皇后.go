/*
 * @lc app=leetcode.cn id=51 lang=golang
 *
 * [51] N皇后
 */

// @lc code=start
func solveNQueens(n int) [][]string {
	queens, xysum, xydiff := make([]int, 0), make([]int, 0), make([]int, 0)
	ansn := make([][]int, 0)
	inArr := func(a int, list []int) bool {
		for _, b := range list {
			if b == a {
				return true
			}
		}
		return false
	}
	var backtracing func([]int, []int, []int)
	backtracing = func(queens, xysum, xydiff []int) {
		l := len(queens)
		if l >= n {
			ansn = append(ansn, queens)
			return
		}
		for i := 0; i < n; i++ {
			if ok1, ok2, ok3 := inArr(i, queens), inArr(l+i, xysum), inArr(l-i, xydiff); !ok1 && !ok2 && !ok3 {
				backtracing(append(queens, i), append(xysum, l+i), append(xydiff, l-i))
			}
		}
	}
	backtracing(queens, xysum, xydiff)
	return func(ansn [][]int) [][]string {
		rets := make([][]string, 0)
		for i := 0; i < len(ansn); i++ {
			ret := make([]string, 0)
			for j := 0; j < n; j++ {
				retv := ""
				for k := 0; k < n; k++ {
					if k == ansn[i][j] {
						retv = retv + "Q"
					} else {
						retv = retv + "."
					}
				}
				ret = append(ret, retv)
			}
			rets = append(rets, ret)
		}
		return rets
	}(ansn)
}

// @lc code=end

