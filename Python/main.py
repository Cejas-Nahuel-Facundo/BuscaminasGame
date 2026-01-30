from engine import engine, Juego

juego = engine.CrearJuego(8,10)

print("Juego Creado:", juego)

res = engine.JUEGO_REVELAR(juego, 0, 0)
print("Click Izquierdo:", res)

res = engine.JUEGO_FLAGS(juego, 1, 1)
print("Click Derecho:", juego)

engine.DestruirJuego(juego)
print("Juego Destruido:", juego)

