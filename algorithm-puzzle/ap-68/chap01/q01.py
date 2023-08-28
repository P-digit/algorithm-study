N = 11
result = 0

while (not result) :
    N += 2

    R_N = str(N)[-1::-1]
    chk_dec = (N == int(R_N))


    N_bin = bin(N).replace("0b", '')
    R_bin = N_bin[-1::-1]
    chk_bin = (int(N_bin) == int(R_bin))


    N_oct = oct(N).replace("0o", '')
    R_oct = N_oct[-1::-1]
    chk_oct = (int(N_oct) == int(R_oct))

    if (chk_dec and chk_bin and chk_oct):
        result = N
        break

print(result)

