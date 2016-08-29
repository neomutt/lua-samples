local function PrintNRetVals ( ...)
	local nargs = select ( '#', ...)
	print ("Number of values returned: " .. nargs)
end

local function ReturningSomething()
	return "hello"
end

local function ReturningNil()
	return nil
end

local function ReturningNothing()
	return
end

PrintNRetVals (ReturningSomething())	--> 1
PrintNRetVals (ReturningNil())		--> 1
PrintNRetVals (ReturningNothing())	--> 0

