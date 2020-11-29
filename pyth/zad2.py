import functools


def pamiec(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):

        if not wrapper.instance:
            wrapper.instance = cls(*args, **kwargs)

        
        ######
        return wrapper


@pamiec
def fibonacci(n):
    return n if 0 <= n < 2 else fibonacci(n - 1) + fibonacci(n - 2)


print(fibonacci(2))