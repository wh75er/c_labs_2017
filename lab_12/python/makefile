main:
	gcc -fPIC -shared func.c -o libfunc.so
	python main.py
	@echo
	rm *.so
	rm -rf __pycache__

test:
	gcc -fPIC -shared func.c -o libfunc.so
	python test.py
	@echo
	rm *.so
	rm -rf __pycache__


	
