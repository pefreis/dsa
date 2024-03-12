PI = 3.14159

def area(radius: float) -> float:
    return radius * radius * PI
    
r = input()
a = area(float(r))
print(f'A={a:.4f}')