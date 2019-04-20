set(ASSETS_PREFIX assets/)

make_atlas(timerfont TIMERFONT_TEXTURE TIMERFONT_ATLAS ${ASSETS_PREFIX} 256
	sprites/timer/Num0.png
	sprites/timer/Num1.png
	sprites/timer/Num2.png
	sprites/timer/Num3.png
	sprites/timer/Num4.png
	sprites/timer/Num5.png
	sprites/timer/Num6.png
	sprites/timer/Num7.png
	sprites/timer/Num8.png
	sprites/timer/Num9.png
)

set(ASSETS
	MODEL
#		models/hovercraft.obj
#		models/plane.obj
#		models/terrain.obj
#		models/testmap.obj
#		models/testplane.obj
#		models/testdip.obj
	TEXTURE
#		IA8    CLAMP  BILINEAR textures/hovercraftGlobal.png
#		I8     CLAMP  BILINEAR textures/hovercraftShade.png
#		I4     REPEAT NEAR     textures/checkerboard.png
		CI8    CLAMP  NEAR     sprites/desire.png
		I4     CLAMP  BILINEAR ABS ${TIMERFONT_TEXTURE}
	SHADER
#		shaders/hovercraft.tev
		shaders/font.tev
		shaders/fade.tev
		shaders/test.tev
	BIN
		audio/music.ogg
		ABS ${TIMERFONT_ATLAS}
)