#-- CEDULAS

#---------------VARIAVEIS
valor =  gets.to_i

cedulas = [100, 50, 20, 10, 5, 2, 1]
cedulas1 = [100, 50, 20, 10, 5, 2]
menor = []
menor1 = []
comb = 0
comb1 = 0

qtd2 = 0
qtd5 = 0
qtd10 = 0
qtd20 = 0
qtd50 = 0
qtd100 = 0
val = valor

divisivel = false
invalido = false
#------------------------------------

#------------- HOUVER UMA CEDULA

if valor > 0 
for i in 0..5
  if valor == cedulas[i]
    menor << cedulas[i]
  end
end
#------------- MENOR QTD DE CEDULAS
if menor.empty?
for i in 0..6
    comb = valor - cedulas[i]
    while comb >= 0
      menor << cedulas[i] 
      comb = comb - cedulas[i]
       if comb < 0
        valor = comb + cedulas[i]
        break
      end   
    end
  end
end
#------------ SE SOBRA 1
for i in 0..menor.length
  if menor[i]  == 1
    divisivel = true
    break
  end
end
#-------------------------

if divisivel
  menor = [2, 2, 2]
    if val == 3 or val == 1
      invalido = true
    end
    if val == 8
      menor << 2
    elsif val == 11
      menor << 5
    else val > 11
      val = val - 6
    for i in 0..5
      comb = val - cedulas1[i]
      while comb >= 0
        menor << cedulas[i] 
        comb = comb - cedulas[i]
        if comb < 0
          val = comb + cedulas[i]
          break
        end   
      end
    end
  end
end


if invalido
  print "Valor inválido"
else
  print menor.sort
# -------- QUANTIDADE
  for i in 0..menor.length-1
    if menor[i] == 2
      qtd2 += 1
    elsif menor[i] == 5
      qtd5 += 1
    elsif menor[i] == 10
      qtd10 += 1
    elsif menor[i] == 20
      qtd20 += 1
    elsif menor[i] == 50
      qtd50 += 1
    else
      qtd100 += 1
    end
  end

  puts ""
  puts "Quantidades de cédulas 2: #{qtd2}"
  puts "Quantidades de cédulas 5: #{qtd5}"
  puts "Quantidades de cédulas 10: #{qtd10}"
  puts "Quantidades de cédulas 20: #{qtd20}"
  puts "Quantidades de cédulas 50: #{qtd50}"
  puts "Quantidades de cédulas 100: #{qtd100}"
end

else
  print "Valor inválido"
end
