.name "ZARGON"
.comment "I will devour all life"

main:
        sti        r1,    %:groundhog, %1
        fork    %:init

groundhog:
        live    %1
        ld        %0, r16
        fork    %:forkpoint
        zjmp    %:groundhog

init:
        live    %1
        fork    %:xmas
        ld        %0, r2

xmas:
        ld        %57672192,    r2
        ld        %318992387,    r3    
forkpoint:
        live    %1
        fork    %:forkpoint

st        r2,    15
st        r3,    -1
live    %1
ld        %0, r16
