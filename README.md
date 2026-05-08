# Projeto de Monitoramento de Buracos - São Carlos-SP

Este repositório reúne todos os programas desenvolvidos para o trabalho de monitoramento de buracos em vias urbanas, utilizando sensores de aceleração, GPS e visualização em mapas interativos.

---

## 📟 Programas Arduino

- **teste_sensores.ino**  
  Código de teste para validar o funcionamento do acelerômetro (MPU6050).  
  Imprime valores de aceleração no monitor serial.

- **gps_coleta.ino**  
  Integração com módulo GPS (NEO-6M).  
  Captura latitude e longitude junto com dados de aceleração.

- **envio_thingspeak.ino**  
  Conexão com Wi-Fi (ESP8266/ESP32).  
  Envia dados de aceleração e coordenadas para o canal ThingSpeak.

---

## ☁️ ThingSpeak

- **configuracao.txt**  
  Documento com informações sobre os campos do canal e chaves de API.

- **interpretacao.m**  
  Script MATLAB para leitura dos dados do canal, cálculo da magnitude da aceleração e classificação dos buracos segundo Kumar & Dahiya (2016).

---

## 📊 Classificação dos Buracos

Baseada em **Kumar & Dahiya (2016)**:

| Categoria | Faixa de aceleração (m/s²) | Equivalente em g | Descrição |
|-----------|-----------------------------|------------------|-----------|
| 1 (Pequeno) | 11,00 – 15,99 m/s² | ~1,12 – 1,63 g | Irregularidade leve |
| 2 (Médio)   | 16,00 – 20,99 m/s² | ~1,63 – 2,14 g | Impacto perceptível |
| 3 (Grande)  | ≥ 21,00 m/s²       | ≥ ~2,14 g       | Impacto severo |

---

## 🌐 Visualização Final

- **index.html**  
  Página web com Leaflet para visualização dos buracos em mapa interativo.  
  - Integração com CSV exportado do ThingSpeak.  
  - Cores vivas para classificação:  
    - Amarelo → Pequeno  
    - Laranja → Médio  
    - Vermelho → Grande  
  - Ajuste automático de zoom com `fitBounds`.  
  - Legenda explicativa com cores e categorias.

---

## 📂 Estrutura do Repositório

projeto-buracos/
│
├── arduino/
│   ├── teste_sensores.ino
│   ├── gps_coleta.ino
│   └── envio_thingspeak.ino
│
├── thingspeak/
│   ├── interpretacao.m
│   └── configuracao.txt
│
├── web/
│   └── index.html
│
└── README.md

---

## 📚 Referência

- Kumar, P., & Dahiya, S. (2016). *Pothole detection using accelerometer data*.  
  Trabalho acadêmico que fundamenta a classificação dos buracos por aceleração.

---

## 🚀 Como usar

1. **Arduino**: carregar os códigos nos módulos (ESP8266/ESP32 + sensores).  
2. **ThingSpeak**: configurar canal e API keys, receber dados.  
3. **MATLAB**: interpretar dados e classificar buracos.  
4. **HTML/Leaflet**: visualizar buracos em mapa interativo.
