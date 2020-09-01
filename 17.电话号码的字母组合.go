/*
 * @lc app=leetcode.cn id=17 lang=golang
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

var phonemap = map[string]string{
	"0": "",
	"1": "",
	"2": "abc",
	"3": "def",
	"4": "ghi",
	"5": "jkl",
	"6": "mno",
	"7": "pqrs",
	"8": "tuv",
	"9": "wxyz",
}

func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}
	ans := make([]string, 0)
	var bt func(int, string)
	bt = func(idx int, cur string) {
		if idx >= len(digits) {
			ans = append(ans, cur)
		} else {
			digit := string(digits[idx])
			letters := phonemap[digit]
			for i := 0; i < len(letters); i++ {
				bt(idx+1, cur+string(letters[i]))
			}
		}
	}
	bt(0, "")
	return ans
}

// @lc code=end

