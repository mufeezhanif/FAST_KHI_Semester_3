include irvine32.inc
; This module contains our game code. This can be spread over multiple sectors on the disc.
; The boot sector loads the sectors containing this module into memory. Once this module is loaded, our game starts.

; Game state constants


start_pos_x EQU 10
start_pos_y EQU 10
VGA_WIDTH EQU 319
VGA_HEIGHT EQU 119
PLAYER_START_X EQU 160
PLAYER_START_Y EQU 170
PLAYER_LENGTH EQU 20
PLAYER_WIDTH EQU 10
PLAYER_VELOCITY EQU 5
ENEMY_START_X EQU 0
ENEMY_START_Y EQU 0
ENEMY_LENGTH EQU 20
ENEMY_WIDTH EQU 5
ENEMY_X_VELOCITY EQU 1
ENEMY_Y_VELOCITY EQU 10
ENEMY_DIRECTION EQU 1
BULLET_START_Y EQU 200
BULLET_START_X EQU 0
BULLET_Y_VELOCITY EQU 2
BULLET_IS_VISIBLE EQU 0
ALIEN_BULLET_START_Y EQU 200
ALIEN_BULLET_START_X EQU 0
ALIEN_BULLET_Y_VELOCITY EQU 2
ALIEN_BULLET_IS_VISIBLE EQU 0
SCORE_POS_X EQU 1
SCORE_POS_Y EQU 23
SCORE_COLOR EQU 14

ORG 9000h

jmp _stage2_start

; Structure definitions

PlayerStruc STRUCT
    pos_x DW ?
    pos_y DW ?
    r_length DW ?
    r_width DW ?
    x_velocity DW ?
PlayerStruc ENDS

Point STRUCT
    pos_x DW ?
    pos_y DW ?
Point ENDS

EnemyStruc STRUCT
    pos_x DW ?
    pos_y DW ?
    r_length DW ?
    r_width DW ?
    x_velocity DW ?
    y_velocity DW ?
    x_direction DB ?
EnemyStruc ENDS

BulletStruc STRUCT
    pos_x DW ?
    pos_y DW ?
    is_visible DB ?
    y_velocity DW ?
BulletStruc ENDS

EnemyBulletStruc STRUCT
    pos_x DW ?
    pos_y DW ?
    is_visible DB ?
    y_velocity DW ?
EnemyBulletStruc ENDS

player PlayerStruc <>
alien EnemyStruc <>
bullet BulletStruc <>
alien_bullet EnemyBulletStruc <>
pt Point <>
score DW 0

_stage2_start:
    mov ax, 0013h 
    int 10h 
    call clear_screen 

game_loop:
    call game_state_update 
    call draw 
    push 0 
    push 0FFFh 
    call delay 
    jmp game_loop 

init:
    mov word ptr [pt.pos_x], start_pos_x 
    mov word ptr [pt.pos_y], start_pos_y 
    ret 

; Subroutine to update game state 
game_state_update:
    push ax 
    push bx 
    push cx 

    mov ah, 1h 
    int 16h 
    jz input_handling_done 

    xor ah, ah 
    int 16h 

    cmp al, 'a' 
    jz move_left 

    cmp al, 'd' 
    jz move_right 

    cmp al, ' ' 
    jz spawn_bullet 

    jmp .input_handling_done

.move_left:
    mov bx, word[player+PlayerStruc.pos_x]                     ; Reduce X coordinate of player but make sure its left edge
    sub bx, word[player+PlayerStruc.x_velocity]                ; is not leaving the screen.
    cmp bx, 0
    jl .input_handling_done
    mov word[player+PlayerStruc.pos_x], bx
    jmp .input_handling_done

.move_right:
    mov bx, word[player+PlayerStruc.pos_x]                      ; Increase X coordinate of player but make sure right edge 
    add bx, word[player+PlayerStruc.x_velocity]                 ; is not leaving the screen.
    add bx, word[player+PlayerStruc.r_width]
    cmp bx, VGA_WIDTH
    jg .input_handling_done
    sub bx, word[player+PlayerStruc.r_width]
    mov word[player+PlayerStruc.pos_x], bx
    jmp .input_handling_done



            END code


; Subroutine to spawn a player bullet
; To keep things simple, there is only one bullet
; which becomes visible and moved to correct location when
; player hits space. Once the bullet hits the enemy or
; moves out of the screen, we make it invisible and stop
; updating its position to prevent astage of cpu cycles.
; This also means that the player can shoot only one bullet
; at a time.
.spawn_bullet:
    cmp byte[bullet+BulletStruc.is_visible], 1                  ; Spawn bullet only if bullet is invisible. That is the
    je .input_handling_done                                     ; bullet is not currenly in action.
    mov ax, word[player+PlayerStruc.pos_y]
    sub ax, 5
    mov word[bullet+BulletStruc.pos_y], ax                      ; The starting Y of the bullet is player's Y - half its width.
    xor dx, dx
    xor bx, bx
    mov ax, word[player+PlayerStruc.r_length]
    mov bl, 2
    idiv bl
    xor ah, ah
    mov bx, word[player+PlayerStruc.pos_x]
    add bx, ax
    mov word[bullet+BulletStruc.pos_x], bx                       ; Starting X of the bullet is player's X + half its length.
    mov byte[bullet+BulletStruc.is_visible], 1                   ; Make the bullet visible
    jmp .input_handling_done    

.input_handling_done:

    ; The following block randomly generates an Enemy bullet.
    ; For each frame an enemy bullet may or may not get generated.
    ; The chance of a bullet generation is 1/20.
    ; In order to achieve this randomness, we first generate the system time.
    ; We divide the lower 8 byte of the system time with 20. If the remainder is
    ; 1 then we spawn a bullet else not.
    ; Also just like player bullet, there is only one enemy bullet which becomes
    ; visible when we need to generate a bullet and gets invisible when it hits the player
    ; or leaves the screen.
    mov ah, 00h
    int 1ah                                                       ; Interrupt to get system time
    mov ax, dx
    xor dx, dx
    mov cx, 20
    idiv cx                                                       ; Divide the system time by 20
    cmp dx, 1                                                     ; If not 1 then skip bullet generation.
    jne .enemy_bullet_generation_done

    cmp byte[alien_bullet+EnemyBulletStruc.is_visible], 1         ; Spawn bullet only if bullet is invisible. That is
    je .enemy_bullet_generation_done                              ; the bullet is not currently in action.
    mov ax, word[alien+EnemyStruc.pos_y]
    add ax, 2
    mov word[alien_bullet+EnemyBulletStruc.pos_y], ax             ; We want the bullet's Y to be enemy's Y + almost half its width.
    xor dx, dx
    xor bx, bx
    mov ax, word[alien+EnemyStruc.r_length]
    mov bl, 2
    idiv bl
    xor ah, ah
    mov bx, word[alien+EnemyStruc.pos_x]
    add bx, ax
    mov word[alien_bullet+EnemyBulletStruc.pos_x], bx              ; We want the bullet's X to be enemy's X + half its length
    mov byte[alien_bullet+EnemyBulletStruc.is_visible], 1          ; Make the bullet visible


.enemy_bullet_generation_done:

    ; The following block deals with enemy movement. The enemy moves
    ; left to right and right to left to and fro. However when it hits
    ; the right edge of the screen, it moves down as well.
    ; In order to move the enemy we simply multiple direction with
    ; its velocity (speed/magnitude) and the result to its X coordinate.
    ; Whenever the enemy hits either edge, we toggle its direction by
    ; multiplying it with -1. Magnitude of direction is simply one. It
    ; can be considered as a unit vector along X axis.
    mov bx, word[alien+EnemyStruc.pos_x]
    mov ax, word[alien+EnemyStruc.x_velocity]
    imul byte[alien+EnemyStruc.x_direction]                         ; Get actual velocity with driection by multiplying speed with direction
    add bx, ax                                                      ; then add it to player X.
    mov word[alien+EnemyStruc.pos_x], bx
    cmp bx, 0
    jnl .check_for_right_edge
    xor ah, ah
    mov al, byte[alien+EnemyStruc.x_direction]
    mov cl, -1
    imul cl                                                         ; If hitting left edge then change direction
    mov byte[alien+EnemyStruc.x_direction], al
.check_for_right_edge:
    add bx, word[alien+EnemyStruc.r_length]
    cmp bx, VGA_WIDTH
    jl .enemy_movement_done
    xor ah, ah
    mov al, byte[alien+EnemyStruc.x_direction]
    mov cl, -1
    imul cl                                                         ; If hitting right edge, then change direction as well.
    mov byte[alien+EnemyStruc.x_direction], al

    ; move the enemy down
    mov bx, word[alien+EnemyStruc.pos_y]
    add bx, word[alien+EnemyStruc.y_velocity]
    mov word[alien+EnemyStruc.pos_y], bx                            ; Finally move the enemy down as well.

.enemy_movement_done:

    ; Following block is for player bullet movement. If bullet is visible then
    ; keep moving it up by reducing its Y. The bullet is basically a vertical line.
    ; When the lower end of the bullet leaves the top edge of the screen we make it
    ; invisible and stop updating it.
    cmp byte[bullet+BulletStruc.is_visible], 1
    jne .bullet_movement_done

    mov bx, word[bullet+BulletStruc.pos_y]
    sub bx, word[bullet+BulletStruc.y_velocity]
    mov word[bullet+BulletStruc.pos_y], bx
    add bx, 5
    cmp bx, 0
    jnl .bullet_movement_done
    mov byte[bullet+BulletStruc.is_visible], 0

.bullet_movement_done:

    ; Following block is for enemy bullet movement. If the bullet is visible then
    ; keep the bullet moving down. If the top end of the bullet goes below the lower
    ; edge of the screen then we make the bullet invisible and stop updating it.
    cmp byte[alien_bullet+EnemyBulletStruc.is_visible], 1
    jne .enemy_bullet_movement_done

    mov bx, word[alien_bullet+EnemyBulletStruc.pos_y]
    add bx, word[alien_bullet+EnemyBulletStruc.y_velocity]
    mov word[alien_bullet+EnemyBulletStruc.pos_y], bx
    cmp bx, 199
    jng .enemy_bullet_movement_done
    mov byte[alien_bullet+EnemyBulletStruc.is_visible], 0


.enemy_bullet_movement_done:

    ; Following block is for detecting collision between player bullet
    ; and enemy. We try to check if the bullet is outside the enemy
    ; boundaries. If not then its a collision. If there is a collision then
    ; move the enemy to its initial position which is top left corner of the
    ; screen, increase the score and set the bullet to invisible.
    ; Also we make sure bullet is visible before proceeding.
    cmp byte[bullet+BulletStruc.is_visible], 1
    jne .enemy_bullet_collision_detection_done
    mov bx, word[alien+EnemyStruc.pos_x]
    cmp word[bullet+BulletStruc.pos_x], bx
    jl .enemy_bullet_collision_detection_done
    add bx, word[alien+EnemyStruc.r_length]
    cmp word[bullet+BulletStruc.pos_x], bx
    jg .enemy_bullet_collision_detection_done
    mov bx, word[alien+EnemyStruc.pos_y]
    add bx, word[alien+EnemyStruc.r_width]
    cmp word[bullet+BulletStruc.pos_y], bx
    jg .enemy_bullet_collision_detection_done

    mov byte[bullet+BulletStruc.is_visible], 0
    mov word[alien+EnemyStruc.pos_x], ENEMY_START_X
    mov word[alien+EnemyStruc.pos_y], ENEMY_START_Y
    mov word[bullet+BulletStruc.pos_x], BULLET_START_X
    mov word[bullet+BulletStruc.pos_y], BULLET_START_Y
    mov bx, word[score]
    add bx, 5
    mov word[score], bx

.enemy_bullet_collision_detection_done:

    ; Following block is for detecting collision between enemy bullet
    ; and the player. This also works same way as collision detection
    ; between player bullet and the enemy. If there is a collision it
    ; player is dead. If set the bullet invisible, delay for sometime
    ; and reset the game.
    cmp byte[alien_bullet+EnemyBulletStruc.is_visible], 1
    jne .enemy_bullet_player_collision_detection_done
    mov bx, word[player+PlayerStruc.pos_x]
    cmp word[alien_bullet+EnemyBulletStruc.pos_x], bx
    jl .enemy_bullet_player_collision_detection_done
    add bx, word[player+PlayerStruc.r_length]
    cmp word[alien_bullet+EnemyBulletStruc.pos_x], bx
    jg .enemy_bullet_player_collision_detection_done
    mov bx, word[alien_bullet+EnemyBulletStruc.pos_y]
    add bx, 5
    cmp bx, word[player+PlayerStruc.pos_y]
    jl .enemy_bullet_player_collision_detection_done

    mov byte[alien_bullet+EnemyBulletStruc.is_visible], 0
    push 0x2d
    push 0xc6c0
    call delay
    call reset_game


.enemy_bullet_player_collision_detection_done:

    ; If the enemy manages to move past the Y of player then its
    ; game over. We delay for sometime and reset the game.
    mov bx, word[alien+EnemyStruc.pos_y]
    add bx, word[alien+EnemyStruc.r_width]
    cmp bx, word[player+PlayerStruc.pos_y]
    jl .player_dead_check_done
    push 0x2d
    push 0xc6c0
    call delay
    call reset_game

.player_dead_check_done:

.done:
    pop cx
    pop bx
    pop ax
    ret

; Subroutine for drawing the frame on screen. Ideally no
; game state updation should be happenning here.
draw:

    push ax
    call clear_screen

    push word[score]
    call score_print

    ; draw the player
    mov ax, 9
    push ax
    mov ax, word [player+PlayerStruc.pos_x]
    push ax
    mov ax, word[player+PlayerStruc.pos_y]
    push ax
    mov ax, word[player+PlayerStruc.r_length]
    push ax
    mov ax, word[player+PlayerStruc.r_width]
    push ax
    call draw_rectangle

    ; draw enemy
    mov ax, 13
    push ax
    mov ax, word [alien+EnemyStruc.pos_x]
    push ax
    mov ax, word[alien+EnemyStruc.pos_y]
    push ax
    mov ax, word[alien+EnemyStruc.r_length]
    push ax
    mov ax, word[alien+EnemyStruc.r_width]
    push ax
    call draw_rectangle

    ; draw player bullet
    cmp byte[bullet+BulletStruc.is_visible], 1
    jne .bullet_drawn
    mov ax, 10
    push ax
    mov ax, word [bullet+BulletStruc.pos_x]
    push ax
    mov ax, word [bullet+BulletStruc.pos_y]
    push ax
    add ax, 5
    push ax
    call vline

.bullet_drawn:

    ; draw enemy bullet
    cmp byte[alien_bullet+EnemyBulletStruc.is_visible], 1
    jne .done
    mov ax, 12
    push ax
    mov ax, word [alien_bullet+EnemyBulletStruc.pos_x]
    push ax
    mov ax, word [alien_bullet+EnemyBulletStruc.pos_y]
    push ax
    add ax, 5
    push ax
    call vline


.done:
    pop ax
    ret


; subroutine to add delay
; Params: delay amount in CX:DX
delay:
    push cx
    push dx
    push ax
    push bp
    mov bp, sp
    mov dx, [bp+10]
    mov cx, [bp+12]
    mov ah, 86h
    int 15h

.delay_done:
    pop bp
    pop ax
    pop dx
    pop cx

    ret 4

; subroutine to reset the positions of all the game objects
; and reset score to 0. This is called on Game Over.
reset_game:
    mov word[player+PlayerStruc.pos_x], PLAYER_START_X
    mov word[player+PlayerStruc.pos_y], PLAYER_START_Y
    mov word[alien+EnemyStruc.pos_x], ENEMY_START_X
    mov word[alien+EnemyStruc.pos_y], ENEMY_START_Y
    mov word[bullet+BulletStruc.pos_x], BULLET_START_X
    mov word[bullet+BulletStruc.pos_y], BULLET_START_Y
    mov byte[bullet+BulletStruc.is_visible], 0
    mov byte[alien_bullet+EnemyBulletStruc.is_visible], 0
    mov word[score], 0
    ret

write_string:
    push ax                                     ; save current state of the registers
    push bx
    push cx
    push dx
    push bp
    push es
    
    mov bp, sp
    mov ax, cs
    mov es, ax                                  ; we set es the same as cs and ds

    mov ax, 1300h                               ; ah needs to be 13h
    mov bh, 00h                                 ; page number
    mov bl, byte[bp+18]                         ; character attribute which is color in case of graphics mode
    xor cx, cx
    mov cl, byte[bp+16]                         ; number of characters in the string
    xor dx, dx
    mov dl, byte[bp+22]                         ; dl = column or X coordinate
    mov dh, byte[bp+20]                         ; dh = row or Y coordinate
    mov bp, word[bp+14]                         ; es:bp the adress of the string to display
    int 10h


.done:
    pop es                                      ; restore registers
    pop bp
    pop dx
    pop cx
    pop bx
    pop ax

    ret 10

; subroutine to print score on screen after performing itoa
score_print:
    push ax                                      ; save registers
    push bx
    push dx
    push si
    push bp
    mov bp, sp
    mov ax, [bp+12]                               ; the only parameter which is the score
    mov si, score_prefix                          ; First we preint the prefix "Score: "

.print_score_prefix:
    mov bx, SCORE_POS_X
    push bx
    mov bx, SCORE_POS_Y
    push bx
    push SCORE_COLOR
    push word[score_prefix_length]
    push si
    call write_string

    mov bx, word[score_prefix_length]               ; the actual score's X will be just after the prefix
    mov si, score_string                            ; The address to store the string version of actual score

.divideloop:
    mov dl, 10                                      ; We are going to repeatedly divide the score by 10
    idiv dl
    add ah, 48                                      ; Now we add 48 to get the character representation of the remainger which is the digit of our score
    mov byte[si], ah                                ; We store the byte in memory. Note: the digits will be stored in reverse order.
    inc si
    xor ah, ah
    cmp al, 0                                        ; We stop when the quotient of division becomes 0. Note: we have already increased si
    jnz .divideloop

.printloop:
    dec si                                            ; We balance out the extra si increment.
    push bx                                           ; push X
    push SCORE_POS_Y
    push SCORE_COLOR
    push 1
    push si
    inc bx
    call write_string
    cmp si, score_string                               ; If we have reached the beginning of the score string then end the loop.
    jne .printloop

.done:
    pop bp                                             ; Restore all the registers
    pop si
    pop dx
    pop bx
    pop ax

    ret 2


; Function to clear screen before rendering next frame.
clear_screen:
    push ax                                             ; save all registers
    push bx
    push cx
    push es
    push di

    mov al, 0x0                                         ; color of the pixel
    mov ah, al
    mov bx, 0a000h                                      ; VGA memory segment
    mov es, bx
    mov cx, 32000                                       ; We will set 1 word at a time so the loop will take total 64000 / 2 = 32000 iterations
    mov di, 0
    rep stosw                                           ; Store ax (word: 0000h) to memory [es:di]

    pop di                                              ; Restore registers
    pop es
    pop cx
    pop bx
    pop ax

    ret

set_pixel:
    push ax
    push bx
    push cx
    push dx
    push bp
    mov bp, sp

    mov ax, [bp+12]
    cmp ax, 0
    jl .end_pixel
    cmp ax, 199
    jg .end_pixel

    mov bx, [bp+14]
    cmp bx, 0
    jl .end_pixel
    cmp bx, 319
    jg .end_pixel

    mov cx, 320
    imul cx
    add bx, ax

    mov ax, 0a000h
    mov es, ax

    mov al, 9
    mov [es:bx], al

.end_pixel:
    pop bp
    pop dx
    pop cx
    pop bx
    pop ax
    ret 4

; subroutine to draw a line parallel to the X axis
; params: X1, X2, Y
hline:
    push ax                                             ; save registers
    push bx
    push cx
    push dx
    push es
    push di
    push bp
    mov bp, sp

    mov ax, [bp+16]                                      ; bp+16 is the Y coordinate 
    cmp ax, 0                                            ; Y should be between 0 and 199 (inclusive)
    jl .hline_done
    cmp ax, 199
    jg .hline_done

    mov bx, 320                                           ; The plotting will begin from X1+230*Y to X2+320*Y
    imul bx
    mov [bp+16], ax

    mov ax, [bp+20]                                        ; bp+20 is X1
    mov bx, [bp+18]                                        ; bp+18 is X2

    cmp ax, bx
    jle .hline_sort
    xchg ax, bx                                             ; Ideally X1 should be <= X2, if not then swap
.hline_sort:
    cmp ax, 0                                               ; boundary check. Desired bounds: 0 <= X1 <= X2 <= 319
    jge .done_x1
    mov ax, 0

.done_x1:
    cmp bx, 319
    jle .done_x2
    mov bx, 319

.done_x2:
    cmp ax, bx
    jg .hline_done

    sub bx, ax                                               ; We need X2-X1 then plotting simply becomes filling the pixels
    inc bx                                                   ; starting from X1+320*Y till X2-X1 pixels after that.
    mov cx, bx
    
    add ax, [bp+16]
    mov di, ax                                               ; We store X1+320*Y in di which is our starting point

    mov ax, 0a000h                                           ; this is the VGA memory segment adress
    mov es, ax

    mov ax, [bp+22]                                          ; the color of the line
    cld
    rep stosb                                                ; repeatedly copy ax to [ES:DI] till cx is 0

.hline_done:
    pop bp                                                   ; Restore registers
    pop di
    pop es
    pop dx
    pop cx
    pop bx
    pop ax
    ret 8

; Subroutine to draw a line parallel to Y axis
; Params: X, Y1, Y2
vline:
    push ax                                                   ; Saving registers
    push bx
    push cx
    push dx
    push es
    push bp
    mov bp, sp

    mov ax, [bp+18]                                            ; bp+18 is X coordinate
    cmp ax, 0                                                  ; Bound check on X
    jl .vline_done
    cmp ax, 319
    jg .vline_done

    mov ax, [bp+16]                                            ; bp+16 is Y1                               
    mov bx, [bp+14]                                            ; bp+14 is Y2

    cmp ax, bx                                                 ; Y1 should be less than Y2 if not then swap
    jle .vline_sort
    xchg ax, bx

.vline_sort:
    cmp ax, 0                                                   ; perform boundary check. Desired condition is 0 <= Y1 <= Y2 <= 199
    jge .done_y1
    mov ax, 0

.done_y1:
    cmp bx, 199
    jle .done_y2
    mov bx, 199


.done_y2:
    cmp ax, bx
    jg .vline_done

    sub bx, ax                                                   ; Here the algorithm is a bit different from horizontal line. Each pixel on
    inc bx                                                       ; a vertical line is exactly 320 pixels away from the previous pixel. So we start with
    mov cx, bx                                                   ; X+320*Y1 pixel and keep coloring the pixel which is 320 pixels away from it for Y2-Y1 times.

    mov bx, 320
    imul bx
    add ax, [bp+18]
    mov bx, ax                                                    ; bx now contains X+320*Y1 which is the starting pixel

    mov ax, 0A000h
    mov es, ax

    mov al, [bp+20] 

.vline_loop:
    mov [es:bx], al                                                ; move al to [ES:DI], add 320 to current pixel and repeat
    add bx, 320
    loop .vline_loop

.vline_done:
    pop bp                                                         ; restore registers
    pop es
    pop dx
    pop cx
    pop bx
    pop ax
    ret 8

; Subroutine to draw a rectangle
draw_rectangle:
    push ax                                                         ; Save registers
    push bx
    push cx
    push dx
    push bp
    mov bp, sp

    ; [bp+12] -> breadth
    ; [bp+14] -> length
    ; [bp+16] -> y
    ; [bp+18] -> x
    ; [bp+20] -> color

    mov ax, [bp+18]
    mov bx, [bp+16]
    mov cx, [bp+20]
    push cx
    push ax
    add ax, [bp+14]
    push ax
    push bx
    call hline                                                       ;  draw a line from (X,Y) to (X+length,Y)
    push cx
    push ax
    push bx
    add bx, [bp+12]
    push bx
    call vline                                                       ; draw a line from (X+length,Y) to (X+length,Y+width)
    push cx
    push ax
    sub ax, [bp+14]
    push ax
    push bx
    call hline                                                       ; draw a line from (X+length,Y+width) to (X,Y+width)
    push cx
    push ax
    push bx
    sub bx, [bp+12]
    push bx
    call vline                                                       ; draw a line from (X,Y+width) to (X,Y)

.rectangle_done:
    pop bp                                                           ; restore registers
    pop dx
    pop cx
    pop bx
    pop ax
    ret 10

            TIMES DIRECTIVE NOT INCLUDED