/*
 * @lc app=leetcode.cn id=657 lang=golang
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
func judgeCircle(moves string) bool {
	x, y := 0, 0
	for _, v := range moves {
		switch string(v) {
		case "R":
			y++
		case "L":
			y--
		case "U":
			x--
		case "D":
			x++
		default:
		}
	}
	if x==0 && y ==0 {
		return true
	} else {
		return false
	}

}

// @lc code=end

