f = open('logs.txt', 'r')
logs = f.read()
ips = logs.split('\n')

frequency = {}

for ip in ips:
    frequency[ip] = frequency.get(ip, 0) + 1

print(frequency)

