

#ifndef ARR_H_
#define ARR_H_

//calcula maximo de un array
int arr_calcularMaximoInt(int array[], int limite, int* pResultado);

//calcula minimo de un array
int arr_calcularMinimoInt(int array[], int limite, int* pResultado);

//calcula el promedio de los numeros de un array
int arr_calcularPromedioInt(int array[], int limite, float* pResultado);

//carga valores int en un array
int arr_cargarValoresInt(int array[], int limite);

//ordena array burbujeo menor a mayor
int arr_ordenarArrayMenorMayor(int array[], int limite);

//ordena array burbujeo mayor a menor
int arr_ordenarArrayMayorMenor(int array[], int limite);


#endif /* ARR_H_ */
