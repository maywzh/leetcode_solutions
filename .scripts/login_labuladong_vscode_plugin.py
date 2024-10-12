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
cookie_str = (
    "aliyungf_tc=abea4e5094fffaaa7ae224ddab419999a36cafb90f4495751f24d95ebab12be5; "
    "sl-session=G0X2amDaCWeB2xryxUeDvA==; "
    "_bl_uid=ajmaU2Oa4603appLUbFF5w35tjIq; "
    "messages=W1siX19qc29uX21lc3NhZ2UiLDAsMjUsIlx1NjBhOFx1NWRmMlx1N2VjZlx1NzY3Ylx1NTFmYSJdXQ:1szQbc:BbGoCj_tYbPYOvGapZnTOdT-pNwl6xIyFFPgJPCuw0Q; "
    "csrftoken=3i3nMz7k6HhahLiL35pE8e29VSN80CuWjkHRwXcWZMIPvIA7QHDtQPflq4IWg4ni; "
    "LEETCODE_SESSION=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJfYXV0aF91c2VyX2lkIjoiMTQ5ODkwIiwiX2F1dGhfdXNlcl9iYWNrZW5kIjoiYWxsYXV0aC5hY2NvdW50LmF1dGhfYmFja2VuZHMuQXV0aGVudGljYXRpb25CYWNrZW5kIiwiX2F1dGhfdXNlcl9oYXNoIjoiZWViMjNlZDVkZDU3NGIzOGI1MjkyNjJhOThhYTg1MWQ5MTkwMTkwZDgxM2Q1NDY5ZGUyMWIwYmEzNGMwNTA5OSIsImlkIjoxNDk4OTAsImVtYWlsIjoibWF5d3poQGdtYWlsLmNvbSIsInVzZXJuYW1lIjoibWF5d3poIiwidXNlcl9zbHVnIjoibWF5d3poIiwiYXZhdGFyIjoiaHR0cHM6Ly9hc3NldHMubGVldGNvZGUuY24vYWxpeXVuLWxjLXVwbG9hZC91c2Vycy9tYXl3emgvYXZhdGFyXzE1OTg5MzgyMjMucG5nIiwicGhvbmVfdmVyaWZpZWQiOnRydWUsImRldmljZV9pZCI6IjUyMTRlMTUyMzUzNWNkY2MzYmJkZjUwY2EwNTQzYjBhIiwiaXAiOiIxOTIuMTAyLjIwNC40MSIsIl90aW1lc3RhbXAiOjE3Mjg2OTUyNzkuMDMxODY1NiwiZXhwaXJlZF90aW1lXyI6MTczMTI2NTIwMCwidmVyc2lvbl9rZXlfIjowfQ.1wuD5BloWkOeDoA2Dvn0fREXUSFs88mmNT7gjoiscWQ"
)

# 解析 cookie 并输出结果
parsed_result = parse_cookie(cookie_str)

# 将结果保存为 user.json
with open("./user.json", "w", encoding="utf-8") as json_file:
    json.dump(parsed_result, json_file, ensure_ascii=False, indent=4)

print("结果已保存到 user.json")
