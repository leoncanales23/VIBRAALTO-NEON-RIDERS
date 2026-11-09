# VibraAlto – Neon Riders 🛹

Juego de skate en Unreal Engine (C++) para el desafío con Sergio Labbe.

## Qué incluye
- `SkateParkWorld`: skatepark básico (piso, 2 rampas, cajón de trucos, rail).
- `SkaterCharacter`: personaje en tercera persona (placeholder) — WASD, mouse, Espacio.
- `VibraAltoGameMode`: usa al skater y crea el skatepark solo si el nivel no lo tiene.

## Cómo abrirlo
1. Clic derecho en `VibraAlto.uproject` → *Switch Unreal Engine version* (elige la que tengas instalada; el archivo dice 5.4).
2. *Generate Visual Studio project files* y abre el `.sln`, o simplemente haz doble clic en el `.uproject`.
3. Compila y pulsa **Play** en un nivel vacío: aparece el skatepark y tu skater.

## Si ya tienes tu proyecto VibraAlto
Copia `Source/VibraAlto/*.h|*.cpp` a tu carpeta `Source/VibraAlto/` y reemplaza `Config/DefaultEngine.ini` (o agrega solo la sección `GameMapsSettings`).

## Próximos pasos
Half-pipe, sistema de trucos y puntaje, animaciones/skater real, estética neón.
