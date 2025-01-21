input();v=range(1024)
print("? "+' '.join(list(map(str,v))))
print('!',int(input())-sum(v)*1024+1)