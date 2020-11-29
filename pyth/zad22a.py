import functools


def singleton(cls):
    """Singleton class (only one instance)"""

    @functools.wraps(cls)
    def wrapper(*args, **kwargs):
        if not wrapper.instance:
            wrapper.instance = cls(*args, **kwargs)
        return wrapper.instance

    wrapper.instance = None
    return wrapper


@singleton
class Jeden:
    pass


obiekt1 = Jeden()
obiekt2 = Jeden()
print(id(obiekt1))
print(id(obiekt2))