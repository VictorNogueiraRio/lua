local tests = {
  normal = math.sin,
  quick = math.qsin,
}

local sin = tests[arg[1]]
local pi = math.pi

for i =1, 3e8 do
  sin(pi)
end
