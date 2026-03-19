#ifndef WEBPAGES_H
#define WEBPAGES_H

#include <Arduino.h>

// Página de configuração WiFi (modo AP)
const char config_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>ESP32 - Configurar WiFi</title>
    <style>
      *{box-sizing:border-box; margin:0; padding:0;}
      body{font-family:Arial; background:#0f1117; color:#e0e0e0; min-height:100vh; display:flex; align-items:center; justify-content:center; padding:1rem;}
      .card{background:#1a1d27; border:1px solid #2a2d3e; border-radius:12px; padding:2rem; width:100%; max-width:400px;}
      h1{text-align:center; color:#4da6ff; margin-bottom:1.5rem; font-size:1.4rem;}
      label{display:block; margin-top:1.2rem; font-size:0.85rem; color:#a0a0b0; font-weight:bold; letter-spacing:0.05em; text-transform:uppercase;}
      input{width:100%; padding:0.6rem 0.8rem; margin-top:0.4rem; background:#0f1117; border:1px solid #2a2d3e; border-radius:6px; color:#e0e0e0; font-size:15px; outline:none; transition:border-color 0.2s;}
      input:focus{border-color:#4da6ff;}
      button{width:100%; padding:0.75rem; margin-top:1.8rem; background:#4da6ff; color:#0f1117; border:none; border-radius:6px; font-size:15px; font-weight:bold; cursor:pointer; transition:background 0.2s;}
      button:hover{background:#76bcff;}
      .info{color:#ffffff; margin-top:1.2rem; font-size:14px; border-top:1px solid #2a2d3e; padding-top:1rem;}
    </style>
  </head>
  <body>
    <div class="card">
      <h1>Configurar WiFi</h1>
        <form action="/save" method="POST">
        <label for="ssid">Nome da Rede (SSID)</label>
        <input type="text" id="ssid" name="ssid" placeholder="Sua rede WiFi" required>
        <label for="password">Senha</label>
        <input type="password" id="password" name="password" placeholder="••••••••">
        <button type="submit">Salvar e Conectar</button>
      </form>
    </div>
  </body>
</html>
)rawliteral";

// Página de status (após conexão bem-sucedida)
const char status_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>ESP32 - Status</title>
    <style>
      *{box-sizing:border-box; margin:0; padding:0;}
      body{font-family:Arial; background:#0f1117; color:#e0e0e0; min-height:100vh; display:flex; align-items:center; justify-content:center; padding:1rem;}
      .card{background:#1a1d27; border:1px solid #2a2d3e; border-radius:12px; padding:2rem; width:100%; max-width:440px; text-align:center;}
      h1{color:#3ecf6a; margin-bottom:1.5rem; font-size:1.4rem;}
      .status{background:#0f1117; border:1px solid #2a2d3e; border-radius:8px; padding:1.2rem; margin-bottom:1.5rem;}
      .label{font-size:12px; color:#555868; text-transform:uppercase; letter-spacing:0.05em; margin-bottom:0.3rem;}
      .value{font-size:16px; color:#a0a0b0;}
      .value strong{color:#e0e0e0;}
      .ip{font-size:28px; font-weight:bold; color:#4da6ff; margin-top:0.2rem;}
      .divider{border:none; border-top:1px solid #2a2d3e; margin:1.2rem 0;}
      .btn-reset{padding:0.65rem 1.5rem; background:transparent; color:#ff5555; border:1px solid #ff5555; border-radius:6px; font-size:14px; cursor:pointer; transition:background 0.2s, color 0.2s;}
      .btn-reset:hover{background:#ff5555; color:#0f1117;}
    </style>
  </head>
  <body>
    <div class="card">
      <h1>✅ WiFi Conectado</h1>
      <div class="status">
        <div class="label">Rede</div>
        <div class="value"><strong>%SSID%</strong></div>
        <hr class="divider">
        <div class="label">Endereço IP</div>
        <div class="ip">%IP%</div>
      </div>
      <button class="btn-reset" onclick="if(confirm('Limpar configurações WiFi?'))location.href='/reset'">Resetar configurações WiFi</button>
    </div>
  </body>
</html>
)rawliteral";

// Página de processamento
const char processing_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Conectando...</title>
    <style>
      *{box-sizing:border-box; margin:0; padding:0;}
      body{font-family:Arial; background:#0f1117; color:#e0e0e0; min-height:100vh; display:flex; align-items:center; justify-content:center; padding:1rem;}
      .card{background:#1a1d27; border:1px solid #2a2d3e; border-radius:12px; padding:2.5rem 2rem; width:100%; max-width:380px; text-align:center;}
      h1{color:#e0e0e0; font-size:1.3rem; margin-bottom:2rem;}
      .spinner{border:6px solid #2a2d3e; border-top:6px solid #4da6ff; border-radius:50%; width:56px; height:56px; animation:spin 0.9s linear infinite; margin:0 auto 1.8rem;}
      @keyframes spin{0%{transform:rotate(0deg)} 100%{transform:rotate(360deg)}}
      p{color:#555868; font-size:14px;}
    </style>
    <script>
      setTimeout(()=>window.location.href='/', 8000);
    </script>
  </head>
  <body>
    <div class="card">
      <h1>Conectando ao WiFi...</h1>
      <div class="spinner"></div>
      <p>Aguarde enquanto conectamos à rede.</p>
    </div>
  </body>
</html>
)rawliteral";

#endif // WEBPAGES_H
