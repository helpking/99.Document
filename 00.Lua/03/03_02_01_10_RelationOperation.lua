a = {}; a.x = 1; a.y = 0
b = {}; b.x = 1; b.y = 0
c = a

str = "a == c : "
bStr = (a == c)
print(str .. tostring(bStr))

str = "a ~= b : "
bStr = (a ~= b)
print(str .. tostring(bStr))

str = "a == c and a ~= b : "
bStr = (a == c and a ~= b)
print(str .. tostring(bStr))

