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

![Screenshot from 2024-02-04 19-29-56.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/0551395f-3794-455c-b295-cf98a63dab89/Screenshot_from_2024-02-04_19-29-56.png)

```markdown
./fractol mandelbar //(appreciation for the details)
```

![Screenshot from 2024-02-04 19-30-56.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/882531e7-46c2-4b6b-b285-36d5f5737315/Screenshot_from_2024-02-04_19-30-56.png)

```markdown
./fractol burningship
```

![Screenshot from 2024-02-04 19-31-49.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/f4b3ece8-7c4e-40fd-9ee3-fe2425b059d1/Screenshot_from_2024-02-04_19-31-49.png)

```markdown
./fractol julia -0.1 -0.8
```

![Screenshot from 2024-02-04 19-34-53.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/07e549e0-7e79-48d7-a98a-e6665b5f26de/Screenshot_from_2024-02-04_19-34-53.png)

And I’ll leave you with a small gallery 😊 (needless to say that I now use my fractol as a litteral background generator lol)

![Screenshot from 2024-02-04 19-36-21.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/ba271c42-2ded-4da4-8e08-53d1e7f6b308/Screenshot_from_2024-02-04_19-36-21.png)

![Screenshot from 2023-09-27 19-22-18.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/8db2515e-1cb0-4a84-9231-c5d53e216034/Screenshot_from_2023-09-27_19-22-18.png)

![Screenshot from 2023-09-27 18-24-49.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/ed956dbd-83a1-4f79-9fa5-3cc99078f394/Screenshot_from_2023-09-27_18-24-49.png)

![Screenshot from 2023-09-27 19-22-46.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/b75ddcd0-848d-4bc1-8266-35f872e6f1a9/Screenshot_from_2023-09-27_19-22-46.png)

![Screenshot from 2023-09-27 19-02-48.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/0391fa99-f7c8-4706-8ffc-37c8dc54cda1/Screenshot_from_2023-09-27_19-02-48.png)

![Screenshot from 2023-09-27 19-17-51.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/bc76dd9e-1495-493b-9f74-54a7c8d55010/Screenshot_from_2023-09-27_19-17-51.png)

![Screenshot from 2023-09-27 01-39-35.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/1c868bab-62c4-492e-8560-5816a16bbb89/Screenshot_from_2023-09-27_01-39-35.png)

![Screenshot from 2023-09-27 18-27-42.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/87b87b0f-a93d-41cc-81c8-94700ea26a1e/Screenshot_from_2023-09-27_18-27-42.png)

![Screenshot from 2023-09-27 18-28-16.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/0374b65b-95ff-4870-9028-1c5e2920bc7b/970450f1-5c7b-44ae-83fb-15fb1aaf0427/Screenshot_from_2023-09-27_18-28-16.png)
