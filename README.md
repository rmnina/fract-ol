**Fract-ol** is one of 42-Common-core's first **graphics project**. Using a lightweight graphics library, minilibx, we learn how to manage pixels (visual render of our project), windows related stuffs (creation, maintaining, proper destruction…) and events (mouse and keyboard).

My fract-ol was made using **minilibx-linux**, so to my knowledge, it doesn't work on Mac OS (I haven't tested Windows, but I'm guessing the same goes for it). I'll publish later a version that runs with SDL (compatible with most systems).

To **download** my fract-ol under Linux :

```markdown
git clone https://github.com/rmnina/fract-ol.git
cd fract-ol
rm minilibx-linux
git clone https://github.com/42Paris/minilibx-linux.git
```

To **launch** fract-ol :

```markdown
make && make clean
Julia fractals : ./fractol ["julia"] (optionnal : add [real] [imag])
Mandelbrot fractal : ./fractol ["mandelbrot"]
Burning Ship fractal : ./fractol ["burningship"]
Mandelbar Celtic fractal : ./fractol ["mandelbar"]
```

To **use** fract-ol :

```markdown
---👾👾😏--- Welcome on my fract-ol ---😏👾👾--- 
	You can use the following options :
	⬆ ➡  Move the camera with the directional arrows
	🖱 🖱  Zoom in and out with the mouse scroller
	🌌🎆 Change the Julia equation :
		- W to raise and S to lower the real part
		- D to raise and A tower the imaginary part
// yes this was optimized for QWERTY keyboards i apologize to the AZERTY team
	⌨🔢 Change the colors with the numeric pad: 
		- 1 to lower and 2 to raise the blues and reds 🔵🔴
		- 4 to lower and 5 to raise the greens and pinks 🟢🧶
		- 7 to lower and 8 to raise the purples and yellows 🟣🟡
		- 0 to go back to the original set 🌈
	🎨🖼- Improve the details on your fractal with 9 
	(mind that it will increase the calculation time)
	⌛⌛ Lower the details with 6
	--------------- 👾👾 	ENJOY 👾👾 ---------------
```

### A few examples 🙂

```markdown
./fractol mandelbrot
```

![Screenshot from 2024-02-04 19-29-56](https://github.com/rmnina/fract-ol/assets/118455014/a8250d85-be04-4ed3-8ca3-c0ca8a2fc274)


```markdown
./fractol mandelbar //(appreciation for the details)
```

![Screenshot from 2024-02-04 19-30-56](https://github.com/rmnina/fract-ol/assets/118455014/ecd57900-9fef-40ca-9af7-04dbca4f29c7)


```markdown
./fractol burningship
```

![Screenshot from 2024-02-04 19-31-49](https://github.com/rmnina/fract-ol/assets/118455014/163e561c-f76c-4562-8f93-bb881f7d9b2d)


```markdown
./fractol julia -0.1 -0.8
```

![Screenshot from 2024-02-04 19-34-53](https://github.com/rmnina/fract-ol/assets/118455014/7060426f-1cad-4076-93a4-97d3507da590)


And I’ll leave you with a small gallery 😊 (needless to say that I now use my fractol as a litteral background generator lol)

![Screenshot from 2024-02-04 19-36-21](https://github.com/rmnina/fract-ol/assets/118455014/8fa28ccc-c524-4fa5-9dc8-6a4bb35694d5)
![Screenshot from 2023-09-27 19-22-18](https://github.com/rmnina/fract-ol/assets/118455014/3f3ead08-7dc3-4cbf-a743-a6df4b6597ed)
![Screenshot from 2023-09-27 18-24-49](https://github.com/rmnina/fract-ol/assets/118455014/75fc93d6-4295-43fc-b1d4-c74724798234)
![Screenshot from 2023-09-27 19-13-48](https://github.com/rmnina/fract-ol/assets/118455014/59ee7365-3e04-4b48-8b4a-6214c9c995d1)
![Screenshot from 2023-09-27 19-22-46](https://github.com/rmnina/fract-ol/assets/118455014/d35b3742-c808-4ca0-ab96-49666c74b186)
![Screenshot from 2023-09-27 19-02-48](https://github.com/rmnina/fract-ol/assets/118455014/234d14a0-4aec-4105-be45-de1283bd176f)
![Screenshot from 2023-09-27 19-17-51](https://github.com/rmnina/fract-ol/assets/118455014/eba8b2df-85fb-4298-8b38-1f3f761b28b9)
![Screenshot from 2023-09-27 19-21-50](https://github.com/rmnina/fract-ol/assets/118455014/26f2b4d9-21bd-4052-9063-5fab6e306711)
![Screenshot from 2023-09-27 18-31-23](https://github.com/rmnina/fract-ol/assets/118455014/b61e7c29-a776-401a-8a93-abcffa321b0c)
![Screenshot from 2023-09-27 18-28-16](https://github.com/rmnina/fract-ol/assets/118455014/ed1b169d-ebe1-4324-bca6-0604ba610931)

(I'm sorry this is so cool I could go on for days.....)
