def generate_fibo(num):
  fibo = [0, 1]
  while fibo[-1] <= num:
    fibo.append(fibo[-1] + fibo[-2])
  del fibo[-1]
x = generate_fibo(50)
print(x)


def generate_fibo(num):
  fibo = [0, 1]
  while fibo[-1] <= num:
    fibo.append(fibo[-1] + fibo[-2])
  del fibo[-1]
  return fibo
x = generate_fibo(150)
print(x)
size = len(x)
print(size)   #원소의 개수
