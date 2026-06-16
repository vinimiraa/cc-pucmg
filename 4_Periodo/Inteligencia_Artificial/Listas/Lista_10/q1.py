import random
from gif_generator import GifLogger

class Perceptron:   
    def __init__(self, num_inputs: int, learning_rate: float = 0.1, random_seed: int = None) -> None:
        """
        Inicializa o perceptron com o número de entradas especificado.

        :param num_inputs: Número de entradas
        :param learning_rate: Taxa de aprendizado
        :param random_seed: Semente para geração de números aleatórios
        """
        if random_seed is not None:
            random.seed(random_seed)

        self.num_inputs = num_inputs
        self.learning_rate = learning_rate
        self.weights = [0] * num_inputs
        self.bias_weight = random.uniform(-1, 1)

        self._initialize_weights()
    # __init__
    
    def _initialize_weights(self) -> None:
        """
        Inicializa os pesos com valores aleatórios entre -1 e 1.
        """
        for i in range(self.num_inputs):
            self.weights[i] = random.uniform(-1, 1)
    # _initialize_weights

    def _activation_function(self, value: float) -> int:
        """
        Função de ativação do perceptron

        :param value: Valor de entrada
        :return: 1 se valor > 0, caso contrário 0
        """
        return 1 if value > 0 else 0
    # _activation_function
    
    def _compute_weighted_sum(self, input_vector) -> float:
        """
        Calcula a soma ponderada das entradas mais o bias.

        :param input_vector: Vetor de entrada
        :return: Soma ponderada
        """
        weighted_sum = sum(input_vector[i] * self.weights[i] for i in range(self.num_inputs))
        weighted_sum += self.bias_weight
        return weighted_sum
    # _compute_weighted_sum

    def _compute_error(self, expected: float, predicted: float) -> float:
        """
        Calcula o erro como a diferença entre esperado e previsto.

        :param expected: Valor esperado
        :param predicted: Valor previsto
        :return: Erro
        """
        return expected - predicted
    # _compute_error

    def _adjust_weights(self, input_vector, error: float) -> None:
        """
        Ajusta os pesos com base no erro.

        :param input_vector: Vetor de entrada
        :param error: Erro de previsão
        """
        for i in range(self.num_inputs):
            self.weights[i] += self.learning_rate * error * input_vector[i]
        self.bias_weight += self.learning_rate * error
    # _adjust_weights

    def _predict_single(self, input_vector) -> float:
        """
        Faz uma previsão para uma única entrada.

        :param input_vector: Vetor de entrada
        :return: Previsão (0 ou 1)
        """
        weighted_sum = self._compute_weighted_sum(input_vector)
        return self._activation_function(weighted_sum)
    # _predict_single

    def train(self, input_data, expected_outputs, num_epochs: int, 
              verbose: bool = False, 
              generate_gif: bool = False, gif_name: str = "perceptron_training.gif") -> list:
        """
        Treina o perceptron usando os dados fornecidos.

        :param input_data: Lista de vetores de entrada
        :param expected_outputs: Lista de saídas esperadas
        :param num_epochs: Número de épocas de treinamento
        :param verbose: Mostra informações do treinamento se True
        :param generate_gif: Gera gif do processo de treinamento se True
        :param gif_name: Nome do arquivo GIF
        :return: Instância do perceptron treinado
        """
        epoch = 0
        predictions = []
        logger = GifLogger(input_data, expected_outputs, self) if generate_gif else None

        while predictions != expected_outputs and epoch < num_epochs:
            predictions = []
            for i in range(len(input_data)):
                predicted = self._predict_single(input_data[i])
                error = self._compute_error(expected_outputs[i], predicted)
                predictions.append(predicted)
                
                if error != 0:  # Atualiza apenas se houver erro
                    self._adjust_weights(input_data[i], error)

            epoch += 1

            if verbose:
                print(f'\nÉpoca {epoch}')
                print("-" * 20)
                print(f'Pesos: {self.weights}')
                print(f'Peso do Bias: {self.bias_weight}')
                print(f'Saída esperada: {expected_outputs}')   
                print(f'Saída prevista: {predictions}')
            
            if generate_gif:
                logger.save_frame(epoch)
        
        if generate_gif:
            logger.generate_gif(output_filename=gif_name)

        return self
    # train
# Perceptron

if __name__ == "__main__":
    # Teste com porta lógica AND
    entradas = [[0, 0],
                [0, 1],
                [1, 0],
                [1, 1]]
    saidas_esperadas = [0, 0, 0, 1]
    perceptron_and = Perceptron(num_inputs=2, learning_rate=0.1, random_seed=42)
    perceptron_and.train(entradas, saidas_esperadas, num_epochs=30, verbose=True, 
                         generate_gif=True, gif_name="AND_perceptron.gif")

    # Teste com porta lógica OR
    saidas_esperadas = [0, 1, 1, 1]
    perceptron_or = Perceptron(num_inputs=2, learning_rate=0.1, random_seed=42)
    perceptron_or.train(entradas, saidas_esperadas, num_epochs=100, verbose=True, 
                        generate_gif=True, gif_name="OR_perceptron.gif")

    # Teste com porta lógica XOR
    saidas_esperadas = [0, 1, 1, 0]
    perceptron_xor = Perceptron(num_inputs=2, learning_rate=0.1, random_seed=42)
    perceptron_xor.train(entradas, saidas_esperadas, num_epochs=100, verbose=True, 
                         generate_gif=True, gif_name="XOR_perceptron.gif")
