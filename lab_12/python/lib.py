import ctypes as ct

lib = ct.CDLL('./libfunc.so')
_bycyclic = lib.bycyclic
_squares = lib.squares

def bycyclic(arr, k):
    global _bycyclic

    n = len(arr)
    array = ct.c_float * n

    _bycyclic.argtypes = ct.POINTER(ct.ARRAY(ct.c_float, n)), ct.c_int, ct.c_int

    out = array(*arr)
    _bycyclic(out, n, k)

    for i in range(n):
        arr[i] = out[i]

def squares(in_array, out_array):
    global squares

    n = len(in_array)
    array = ct.c_float * n

    _squares.argtypes = ct.ARRAY(ct.c_float, n), ct.c_int, \
                                ct.ARRAY(ct.c_float, n)

    out = array(*out_array)
    _squares(array(*in_array), n, out)

    for i in range(n):
        out_array[i] = out[i]

