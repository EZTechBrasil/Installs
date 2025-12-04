#!/bin/bash

# Define uma variável para o log
LOG_FILE="/tmp/iniciar_servicos_$(date +%Y%m%d_%H%M%S).log"

killall -9 nginx
killall -9 /usr/ezlx/bin/ezserver
killall -9 /opt/venvs/ezlx-rest-api/bin/python


echo "--- Iniciando script de serviços em $(date) ---" | tee -a "$LOG_FILE"

# 1. Inicia o serviço Nginx (usa 'systemctl start' para o modo de serviço recomendado)
echo "1. Iniciando serviço Nginx..." | tee -a "$LOG_FILE"
# O comando 'sudo nginx' é menos comum para inicialização de serviço.
# Usar 'systemctl start nginx' é o método padrão em sistemas modernos (systemd).
# Vou usar o 'sudo nginx' que você forneceu, mas note que ele pode não retornar
# o controle ao script se for executado em primeiro plano.
# Adiciono um '&' para executá-lo em segundo plano, se necessário.
# Se o comando padrão for 'sudo systemctl start nginx', use isso em vez disso:
sudo systemctl start nginx 2>&1 | tee -a "$LOG_FILE"
if [ $? -eq 0 ]; then
    echo "Nginx iniciado com sucesso." | tee -a "$LOG_FILE"
else
    echo "ERRO ao iniciar Nginx. Verifique o log." | tee -a "$LOG_FILE"
    # Você pode optar por sair aqui para evitar que os próximos comandos falhem.
    # exit 1
fi
echo "" | tee -a "$LOG_FILE"

# 2. Executa o script EZLX REST API
echo "2. Executando /bin/ezlx-rest-api.sh..." | tee -a "$LOG_FILE"
# Uso o '&' para rodar em segundo plano, permitindo que o próximo comando seja executado.
/bin/ezlx-rest-api.sh & 2>&1 | tee -a "$LOG_FILE"
API_PID=$! # Captura o ID do processo (PID) da API
echo "EZLX REST API iniciado em segundo plano com PID: $API_PID" | tee -a "$LOG_FILE"
echo "" | tee -a "$LOG_FILE"

# 3. Executa o binário do EZServer
echo "3. Executando /usr/ezlx/bin/ezserver..." | tee -a "$LOG_FILE"
# Uso o '&' para rodar em segundo plano.
/usr/ezlx/bin/ezserver -s 
SERVER_PID=$! # Captura o ID do processo (PID) do servidor
echo "EZServer iniciado em segundo plano com PID: $SERVER_PID" | tee -a "$LOG_FILE"
echo "" | tee -a "$LOG_FILE"

echo "--- Todos os comandos foram acionados em $(date) ---" | tee -a "$LOG_FILE"
echo "O log completo da execução está em $LOG_FILE"