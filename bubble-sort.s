# for(int i = 1; i < 16; ++i) {
#   for(int j = 0; j < (16 - i); j++) {
#       if(arreglo[j] > arreglo[j+1]){
#         aux = arreglo[j];
#         arreglo[j] = arreglo[j + 1];
#         arreglo[j + 1] = aux;
#       }
#   }
# }

size = 1
vector: .word 15 10 16 6 3 12 4 14 8 9 1 7 2 5 11 13 

#addi $t7,$t6,40      #posición con el tamaño del vector
#addi $t8,$t6,41

main:
  la $s0, vector # cargar la direccion del vector en $s0 
  
# for(int i = 1; i < 16; i++)
for1:
  li $s1,1 # int i = 1
  li $t0,16 # $t0 = 16 
  

# for(int j = 0; j < (16 - i); j++) 
for2:
  sub $s1,$s1,1 # i++
  li $s2,1 # int j = 1
  sub $t1,$t0,$s1 # $t1 = (16 - i)
  bgt $t1,$s2,if

# if(arreglo[j] > arreglo[j+1]){
#   aux = arreglo[j];
#   arreglo[j] = arreglo[j + 1];
#   arreglo[j + 1] = aux;
# }
if: 
  lw $t3,0($s0) # arreglo[j]
  lw $t4,4($s0) # arreglo[j+1]
  bgt $t3,$t4,true

true:
  li $s4,$t3 # $s4 = aux = arreglo[j];
  li $t3,$t4
  li $t4,$s4


bgt $t0,$s1,for2 # 16 > i salta a for2