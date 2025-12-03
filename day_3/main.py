def max_joltage(bank: str, depth: int = 12):
    dp = {}

    def helper(bank, depth):
        if len(bank) == 0 or depth > len(bank) or depth == 0:
            return ""

        if (bank, depth) in dp:
            return dp[(bank, depth)]

        dp[(bank, depth)] = max(
            bank[0] + helper(bank[1:], depth - 1), (helper(bank[1:], depth))
        )

        return dp[(bank, depth)]

    return int(helper(bank, depth))


res = 0

f = open("../data/3.txt")
for line in f.readlines():
    res += max_joltage(line.strip(), 2)
f.close()
print(res)

res = 0
f = open("../data/3.txt")
for line in f.readlines():
    res += max_joltage(line.strip(), 12)

print(res)
f.close()
