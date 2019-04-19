assume cs:code


stack segment 
        db 128 dup (0)
stack ends 

data segment 
        dw 0,0,0,0
data ends


code segment 
start:
        mov ax,stack 
        mov ss,ax 
        mov sp,128
        mov ax,data 
        mov ds,ax 
        mov ax,0
        mov es,ax
        push es:[9*4]
        pop ds:[0]
        push es:[9*4+2]
        pop ds:[2]      ;将原来的int9中断例程的入口地址保存在ds：0、ds：2单元中

        mov word ptr es:[9*4],offset int9
        mov es:[9*4+2],cs       ;在中断向量表中设置新的int9中断例程的入口地址
        


;-----------主要功能---------------        
        mov ax, 0b800h
        mov es, ax
work:
        call int9
        jmp short work




funexit:;-----------以下是恢复原来的int9-------------
        mov ax,0
        mov es,ax

        push ds:[0]
        pop es:[9*4]
        push ds:[2]
        pop es:[9*4+2]


        mov ax, 4c00h
        int 21h

;es:si目标显存地址,十位在ch,个位在cl
print:
        add ch, '0'
        add cl, '0'

        mov byte ptr es:[si], ch
        mov byte ptr es:[si + 1], 21h
        mov byte ptr es:[si + 2], cl
        mov byte ptr es:[si + 3], 21h

        ret

funcA:
        push si
        push cx
        mov si, 5 * 160 + 40 * 2
        mov cx,ds:[4]
        inc cl 
        cmp cl, 10
        jne con1
        mov cl,0
        inc ch
con1:
        mov ds:[4],cx
        call print
        pop cx
        pop si
        ret

funcB:
        push si
        push cx
        mov si, 6 * 160 + 40 * 2
        mov cx,ds:[6]
        inc cl 
        cmp cl, 10
        jne con2
        mov cl,0
        inc ch
con2:
        mov ds:[6],cx
        call print
        pop cx
        pop si
        ret




;---—-以下为新的int 9中断例程--—-

int9:
        push ax 
        push bx
        push es 

        
        in al,60h 
        pushf

        pushf 
        pop bx 
        and bh,11111100b 
        push bx 
        popf 
        call dword ptr ds:[0]      ;对int 指令进行模拟,调用原来的int9中断例程

        ;如果输入的是1
        cmp al,2
        jne f1
        call funcA
        jmp int9ret

        ;如果输入的是2
f1:
        cmp al,3
        jne f2
        call funcB
        jmp int9ret

        ;如果输入的是3，退出
f2:
        cmp al,4
        jne int9ret
        call funexit

int9ret:
        pop es 
        pop bx
        pop ax 
        iret

;delay函数空循环 0x5ffff 次,大概延时1-2S,需要的自行调节cx的值
;本示例中不调用该函数,在完成第3个任务的时候可以搬运这段函数
delay: 
        push ax
        push cx
        mov cx, 5
    s1:
        mov ax, 0ffffh
    s2:
        dec ax
        jnz s2
        dec cx
        jnz s1

        pop cx
        pop ax
        ret

code ends
end start
