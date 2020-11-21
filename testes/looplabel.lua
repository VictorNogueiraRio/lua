j = 0
loop1:: while(j < 10) do
  loop2:: for i=0, 10 do
    print(i)
    break loop1
  end
  j = j + 1
end
