# ESP32 WiFi Manager

Sistema de gerenciamento de WiFi com portal captivo para ESP32.

## Funcionalidades

- ✅ **Portal Captivo**: Se não houver credenciais salvas, o ESP32 inicia em modo AP
- ✅ **Configuração via Web**: Interface amigável para configurar SSID e senha
- ✅ **Persistência**: Credenciais armazenadas em memória flash (Preferences)
- ✅ **Auto-reconexão**: Tenta conectar automaticamente às credenciais salvas
- ✅ **API REST**: Endpoint para controlar LED via JSON
- ✅ **Reset por Hardware**: Botão GPIO0 para limpar configurações

## Como Usar

### 1. Primeira Inicialização (Sem Configuração)

1. O ESP32 inicia em **modo AP** com o nome: `ESP32-Config`
2. Conecte-se a esta rede via celular/computador
3. Acesse no navegador: `http://192.168.4.1`
4. Preencha o SSID e senha da sua rede WiFi
5. Clique em **Conectar**
6. Aguarde — o ESP32 tentará conectar à rede
7. Se bem-sucedido, as credenciais serão salvas automaticamente

### 2. Uso Normal (Com Configuração Salva)

- O ESP32 conecta automaticamente ao WiFi configurado
- Acesse a página de status via IP do ESP32 na sua rede local
- Use o botão **Toggle LED** ou o endpoint `/api/led`

### 3. Resetar Configurações WiFi

**Opção A - Via Web:**
- Acesse a página principal e clique em **Resetar WiFi**

**Opção B - Via Botão Físico (GPIO0/BOOT):**
- Pressione e segure o botão **BOOT** no ESP32 por **3 segundos**
- O ESP reiniciará em modo AP

## API Endpoints

| Endpoint | Método | Descrição |
|----------|--------|-----------|
| `/` | GET | Página principal (AP config ou status) |
| `/save` | POST | Recebe credenciais WiFi (modo AP) |
| `/api/led` | GET | Alterna estado do LED D2 (retorna JSON) |
| `/reset` | GET | Limpa configurações e reinicia |

### Exemplo de uso da API:

```bash
# Alternar LED
curl http://<IP_DO_ESP32>/api/led

# Resposta: {"led":"on"} ou {"led":"off"}
```

## Hardware

- **LED**: GPIO 2 (D2)
- **Botão Reset**: GPIO 0 (botão BOOT integrado)

## Compilar e Upload

```bash
pio run -t upload -e esp32dev
pio device monitor
```

## Monitor Serial

Velocidade: **115200 baud**

O monitor mostrará:
- Status da conexão WiFi
- IP atribuído (modo STA ou AP)
- Requisições HTTP recebidas

## Comportamento do LED

- **Durante conexão**: Pisca rapidamente (250ms)
- **Conectado**: Apagado (HIGH)
- **Controle via API**: Alterna entre ON/OFF

## Dependências

- `espressif32` platform
- `arduino` framework
- `ArduinoJson` 7.4.3

---

**Desenvolvido para ESP32** | Porta 80
