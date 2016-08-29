function test1()
	return 5
end

local a, b = test1()
-- a = 5, b = nil

function test2()
	return 1, 2
end

local c, d, e = test2()
-- c = 1, d = 2, e = nil

function test3()
end

local f, g = test3()
-- f = nil, g = nil
