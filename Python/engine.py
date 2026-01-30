from ctypes import *
import os 
from ctypes import CDLL

class Casilla(Structure):
    _fields_ = [
        ("Mina", c_ubyte),
        ("Bandera", c_ubyte),
        ("Descubierta", c_ubyte),
        ("Adyacentes", c_ubyte),
    ]

class Juego(Structure):
    pass

engine = CDLL(r"E:\usuarios\alumno\Escritorio\BuscaminasGame\engineC\game.dll")

engine.CrearJuego.argtypes = [c_int, c_int]
engine.CrearJuego.restype = POINTER(Juego)

engine.DestruirJuego.argtypes = [POINTER(Juego)]

engine.JUEGO_REVELAR.argtypes = [POINTER(Juego), c_int, c_int]
engine.JUEGO_REVELAR.restype = c_int

engine.JUEGO_FLAGS.argtypes = [POINTER(Juego), c_int, c_int]
engine.JUEGO_FLAGS.restype = c_int

