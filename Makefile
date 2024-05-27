build:
	gcc main.c cerinte.c functii.c liste.c stiva.c graf.c -o clasament -lm

clean:
	rm -f clasament
