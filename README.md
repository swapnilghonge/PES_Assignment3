EXTRA CREDIT QUESTIONS Question : 1 What is the address of your main() function, and what is the size in bytes of your delay() function? Size Byte of Main() is 198 Bytes Size Byte of Delay is 00000040 thats equals to 64 Bytes

Question:2 Show the full disassembly of your delay() function, adding comments to each line to explain the functionality. Answer: 2


00000750 : 750: b580 push {r7, lr} // the variables lr and r7 are pushed into stack.</br>
 752: b084 sub sp, #16 //substract 16h from sp </br>
 754: af00 add r7, sp, #0 // add sp and #0 and store in register r7 </br>
 756: 6078 str r0, [r7, #4] // store the value of r0 in address r7 and #4</br>
  758: 2300 movs r3, #0  // move 0 in register r3 75a: 60fb str r3, [r7, #12] </br>
  // // store the value of r0 in address r7 and #12 75c: e00c b.n 
  778 <delay+0x28> 75e: 2300 movs r3, #0 // move 0 in register r3 </br> 760: 60bb str r3, [r7, #8] // store the value of r3 in address r7 and #8</br> 762: e002 b.n 76a <delay+0x1a></br> 764: 68bb ldr r3, [r7, #8] address pointed to r7, #8 </br> 766: 3301 adds r3, #1 add r3 and #1 and store in r3 </br>768: 60bb str r3, [r7, #8] // store the value of r3 in address r7 and #8</br> 76a: 68bb ldr r3, [r7, #8] address pointed to r7, #8 </br>76c: 4a07 ldr r2, [pc, #28] </br>; (78c <delay+0x3c>) </br>76e: 4293 cmp r3, r2 compare r3 and r2</br> 770: ddf8 ble.n 764 <delay+0x14></br> 772: 68fb ldr r3, [r7, #12] // store the value of r3 in address r7 and #12</br> 774: 3301 adds r3, #1 // add r3 and #1 and store in r3</br> 776: 60fb str r3, [r7, #12] // store the value of r3 in address r7 and #12 </br> 778: 68fa ldr r2, [r7, #12] address pointed to r7, #12 </br> 77a: 687b ldr r3, [r7, #4] address pointed to r7, #4 </br> 77c: 429a cmp r2, r3 compare r3 and r2 </br> 77e: dbee blt.n 75e <delay+0xe></br> 780: 46c0 nop ; (mov r8, r8) </br> 782: 46c0 nop ; (mov r8, r8) 784: 46bd mov sp, r7 786: b004 add sp, #16 </br> 788: bd80 pop {r7, pc} </br> 78a: 46c0 nop ; (mov r8, r8) 78c: 00000671 .word 0x00000671</br>
 