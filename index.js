angular
    .module('plantaIotApp', ['ngSanitize'])
    
    .controller('MainCtrl', ['$http', '$sce', '$timeout', function ($http, $sce, $timeout) {
        var self = this;
        self.settings = {
            baseUrl: 'https://api.thingspeak.com/talkbacks/'
        };
        self.status = {};

        load();

        function load() {
            var config = JSON.parse(localStorage.getItem('config')) || {};
            
            self.settings.channelId = config.channelId;
            self.settings.talkBackIdId = config.talkBackIdId;
            self.settings.writeKey = config.writeKey;
            self.settings.apiUrl = self.settings.baseUrl + '/' + config.talkBackIdId + '/commands.json';
            self.settings.iframeUrl = $sce.trustAsResourceUrl(
                'https://thingspeak.com/channels/' 
                + config.channelId + 
                '/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=20&type=line&update=15'
            );
        };

        self.displayOn = function() {
            var data = { api_key: self.settings.writeKey, command_string: 'LIGAR_VISOR' };

            $http.post(self.settings.apiUrl, data)
                .then(function(result) {
                    self.status = {
                        type: 'info',
                        message: 'Comando enviado com sucesso'
                    };

                    console.log(result);
                })
                .catch(function (error) {
                    self.status = {
                        type: 'danger',
                        message: 'Ocorreu um erro enviando o comando'
                    };

                    console.log(error);
                });
        };

        self.displayOff = function() {
            var data = { api_key: self.settings.writeKey, command_string: 'DESLIGAR_VISOR' };

            $http.post(self.settings.apiUrl, data)
                .then(function(result) {
                    self.status = {
                        type: 'info',
                        message: 'Comando enviado com sucesso'
                    };

                    console.log(result);
                })
                .catch(function(error) {
                    self.status = {
                        type: 'danger',
                        message: 'Ocorreu um erro enviando o comando'
                    };

                    console.log(error);
                });
        };

        self.pumpOn = function() {
            var data = { api_key: self.settings.writeKey, command_string: 'LIGAR_BOMBA' };

            $http.post(self.settings.apiUrl, data)
                .then(function(result) {
                    self.status = {
                        type: 'info',
                        message: 'Comando enviado com sucesso'
                    };

                    console.log(result);
                })
                .catch(function (error) {
                    self.status = {
                        type: 'danger',
                        message: 'Ocorreu um erro enviando o comando'
                    };

                    console.log(error);
                });
        };

        self.pumpOff = function() {
            var data = { api_key: self.settings.writeKey, command_string: 'DESLIGAR_BOMBA' };

            $http.post(self.settings.apiUrl, data)
                .then(function(result) {
                    self.status = {
                        type: 'info',
                        message: 'Comando enviado com sucesso'
                    };

                    console.log(result);
                })
                .catch(function(error) {
                    self.status = {
                        type: 'danger',
                        message: 'Ocorreu um erro enviando o comando'
                    };

                    console.log(error);
                });
        };

        self.saveConfig = function() {
            $('#myModal').modal('hide');

            self.settings.channel = {
                url: 'https://thingspeak.com/channels/' 
                    + self.settings.channelId 
                    + '/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15'
            };

            localStorage.setItem('config', JSON.stringify(self.settings));

            self.status = {
                type: 'info',
                message: 'Configurações salvas com sucesso'
            };
        }
    }]);