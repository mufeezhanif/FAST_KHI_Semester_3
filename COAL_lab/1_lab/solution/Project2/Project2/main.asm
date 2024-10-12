
INCLUDE Irvine32.inc

.data
array byte 61,43,11,52,25
arrayS byte 5 Dup(?)
.code
main PROC

mov al, [array +2]
mov arrayS, al
mov al, [array +4]
mov [arrayS +1], al
mov al, [array +1]
mov [arrayS +2], al
mov al, [array +3]
mov [arrayS +3], al
mov al, array
mov [arrayS +4], al

COMMENT @
If the array size is word or dword then in word, we will access the next elementx
by [array +2] and so on; for dword [array + 4] and so on
@

main ENDP

END main
