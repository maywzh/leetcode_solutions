import json
import re


def parse_cookie(cookie_str):
    # 正则表达式匹配
    session_id_pattern = r"LEETCODE_SESSION=([^;]+)"
    csrf_token_pattern = r"csrftoken=([^;]+)"

    # 提取 LEETCODE_SESSION 和 csrftoken
    session_id = re.search(session_id_pattern, cookie_str)
    csrf_token = re.search(csrf_token_pattern, cookie_str)

    # 获取 cookie 中的所有字段
    cookies = cookie_str.split("; ")

    # 创建结果字典
    result = {
        "login": "maywzh",
        "cookie": cookie_str,
        "sessionId": session_id.group(1) if session_id else None,
        "sessionCSRF": csrf_token.group(1) if csrf_token else None,
    }

    return result


# 输入的 cookie 字符串
with open('./.cookie') as file:
    cookie_str = file.read()

# 解析 cookie 并输出结果
parsed_result = parse_cookie(cookie_str)

# 将结果保存为 user.json
with open("./user.json", "w", encoding="utf-8") as json_file:
    json.dump(parsed_result, json_file, ensure_ascii=False, indent=4)

print("结果已保存到 user.json")
