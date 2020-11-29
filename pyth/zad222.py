import functools


def pamiec(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):


        a = 7
        if not wrapper.instance:
            wrapper.instance = cls(*args, **kwargs)

        

        ######
        return wrapper


@pamiec
def fibonacci(n):
    return n


print(fibonacci(2))