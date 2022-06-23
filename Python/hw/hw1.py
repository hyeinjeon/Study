print('다음에 3개의 선분의 값을 입력하시오.')
a = input('선분1: ')
a = float(a)
b = input('선분2: ')
b = float(b)
c = input('선분3: ')
c = float(c)
if (a < b + c) & (b < a + c) & (c < a + b):
  print('\n세 개의 선분으로 삼각형을 만들 수 있습니다.')
else:
  print('\n세 개의 선분으로 삼각형을 만들 수 없습니다.')
