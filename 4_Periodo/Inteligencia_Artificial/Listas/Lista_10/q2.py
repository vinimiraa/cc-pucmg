import numpy as np

class BackPropagation:
    def __init__(self, num_inputs, num_hidden_neurons, num_outputs,
                 learning_rate=0.1, activation_function='sigmoid', use_bias=True,
                 random_seed=None):
        """
        Inicializa a rede neural com os parâmetros fornecidos.
        :param num_inputs: Número de neurônios na camada de entrada
        :param num_hidden_neurons: Número de neurônios na camada oculta
        :param num_outputs: Número de neurônios na camada de saída
        :param learning_rate: Taxa de aprendizado para atualização dos pesos
        :param activation_function: Função de ativação a ser usada ('sigmoid', 'tanh', 'relu')
        :param use_bias: Se True, inclui bias nas camadas
        :param random_seed: Semente para reprodutibilidade (opcional)
        """
        if random_seed is not None:
            np.random.seed(random_seed)
        self.num_inputs = num_inputs
        self.num_hidden_neurons = num_hidden_neurons
        self.num_outputs = num_outputs
        self.learning_rate = learning_rate
        self.use_bias = use_bias
        self.activation_function_name = activation_function

        self._initialize_weights()

        self.training_loss_history = []

        self._initialize_activation_functions()
    # __init__

    def _initialize_weights(self):
        self.weights_input_to_hidden = np.random.uniform(-1, 1, (self.num_inputs, self.num_hidden_neurons))
        self.weights_hidden_to_output = np.random.uniform(-1, 1, (self.num_hidden_neurons, self.num_outputs))

        if self.use_bias:
            self.bias_hidden_layer = np.random.uniform(-1, 1, (1, self.num_hidden_neurons))
            self.bias_output_layer = np.random.uniform(-1, 1, (1, self.num_outputs))
        else:
            self.bias_hidden_layer = np.zeros((1, self.num_hidden_neurons))
            self.bias_output_layer = np.zeros((1, self.num_outputs))
    # _initialize_weights

    def _initialize_activation_functions(self):
        if self.activation_function_name == 'sigmoid':
            self.activation = self._sigmoid
            self.activation_derivative = self._sigmoid_derivative
        elif self.activation_function_name == 'tanh':
            self.activation = self._tanh
            self.activation_derivative = self._tanh_derivative
        elif self.activation_function_name == 'relu':
            self.activation = self._relu
            self.activation_derivative = self._relu_derivative
        else:
            raise ValueError(f"Função de ativação '{self.activation_function_name}' não suportada.")
    # _initialize_activation_functions

    def _sigmoid(self, x):
        return 1 / (1 + np.exp(-np.clip(x, -500, 500)))

    def _sigmoid_derivative(self, x):
        sig = self._sigmoid(x)
        return sig * (1 - sig)

    def _tanh(self, x):
        return np.tanh(x)

    def _tanh_derivative(self, x):
        return 1 - np.tanh(x) ** 2

    def _relu(self, x):
        return np.maximum(0, x)

    def _relu_derivative(self, x):
        return (x > 0).astype(float)

    def _compute_loss(self, predictions, expected_output):
        return np.mean((predictions - expected_output) ** 2)

    def _compute_gradients(self, input_data, expected_output):
        """Calcula os gradientes para atualização dos pesos"""
        num_samples = input_data.shape[0]

        output_error = self.predicted_output - expected_output
        output_gradient = output_error  # derivada da MSE * sigmoide já aplicada na saída

        grad_weights_hidden_output = (1 / num_samples) * np.dot(self.hidden_output.T, output_gradient)
        grad_bias_output = (1 / num_samples) * np.sum(output_gradient, axis=0, keepdims=True)

        hidden_error = np.dot(output_gradient, self.weights_hidden_to_output.T)
        hidden_gradient = hidden_error * self.activation_derivative(self.hidden_input)

        grad_weights_input_hidden = (1 / num_samples) * np.dot(input_data.T, hidden_gradient)
        grad_bias_hidden = (1 / num_samples) * np.sum(hidden_gradient, axis=0, keepdims=True)

        return grad_weights_input_hidden, grad_bias_hidden, grad_weights_hidden_output, grad_bias_output
    # _compute_gradients

    def _adjust_weights(self, grad_w_ih, grad_b_h, grad_w_ho, grad_b_o):
        """
        Ajusta os pesos e bias da rede neural usando os gradientes calculados.
        :param grad_w_ih: Gradiente dos pesos da camada de entrada para a camada oculta
        :param grad_b_h: Gradiente do bias da camada oculta
        :param grad_w_ho: Gradiente dos pesos da camada oculta para a camada de saída
        :param grad_b_o: Gradiente do bias da camada de saída
        """
        self.weights_input_to_hidden -= self.learning_rate * grad_w_ih
        self.weights_hidden_to_output -= self.learning_rate * grad_w_ho

        if self.use_bias:
            self.bias_hidden_layer -= self.learning_rate * grad_b_h
            self.bias_output_layer -= self.learning_rate * grad_b_o
    # _adjust_weights

    def _forward_pass(self, input_data):
        """
        Executa a passagem direta pela rede neural.
        :param input_data: Dados de entrada (numpy array)
        :return: Saída prevista pela rede neural
        """
        self.hidden_input = np.dot(input_data, self.weights_input_to_hidden) + self.bias_hidden_layer
        self.hidden_output = self.activation(self.hidden_input)

        self.output_input = np.dot(self.hidden_output, self.weights_hidden_to_output) + self.bias_output_layer
        self.predicted_output = self._sigmoid(self.output_input)

        return self.predicted_output
    # _forward_pass

    def _backward_pass(self, input_data, expected_output):
        """
        Executa a passagem reversa para calcular os gradientes e atualizar os pesos.
        :param input_data: Dados de entrada (numpy array)
        :param expected_output: Saída esperada (numpy array)
        """
        gradients = self._compute_gradients(input_data, expected_output)
        self._adjust_weights(*gradients)
    # _backward_pass

    def train(self, input_data, expected_output, num_epochs=1000, verbose=False):
        """
        Treina a rede neural usando o algoritmo de retropropagação.
        :param input_data: Dados de entrada (numpy array)
        :param expected_output: Saída esperada (numpy array)
        :param num_epochs: Número de épocas para treinamento
        :param verbose: Se True, imprime o progresso do treinamento
        """
        for epoch in range(num_epochs):
            predictions = self._forward_pass(input_data)
            loss = self._compute_loss(predictions, expected_output)
            self.training_loss_history.append(loss)

            self._backward_pass(input_data, expected_output)

            if verbose and epoch % 100 == 0:
                print(f"Época {epoch} | Erro: {loss:.6f}")
                # print("-" * 50)
                # print(f"Pesos entrada-oculta:\n{self.weights_input_to_hidden}")
                # print(f"Pesos oculta-saída:\n{self.weights_hidden_to_output}")
                # print(f"Bias oculta:\n{self.bias_hidden_layer}")
                # print(f"Bias saída:\n{self.bias_output_layer}")

        if verbose:
            print(f"Treinamento concluído. Erro final: {self.training_loss_history[-1]:.6f}")
    # train

    def predict(self, input_data):
        """
        Faz previsões com a rede neural treinada.
        :param input_data: Dados de entrada (numpy array)
        :return: Previsões (numpy array)
        """
        predictions = self._forward_pass(input_data)
        return (predictions > 0.5).astype(int)
    # predict
# BackPropagation

if __name__ == "__main__":
    # XOR
    X = np.array([[0, 0],
                  [0, 1],
                  [1, 0],
                  [1, 1]])
    y = np.array([[0], [1], [1], [0]])

    bp = BackPropagation(num_inputs=2, num_hidden_neurons=2, num_outputs=1,
                         learning_rate=0.1, activation_function='sigmoid', use_bias=True, random_seed=42)
    bp.train(X, y, num_epochs=10000, verbose=True)

    predictions = bp.predict(X)
    print("Previsões:")
    print(predictions)

    # AND
    X_and = np.array([[0, 0],
                      [0, 1],
                      [1, 0],
                      [1, 1]])    
    y_and = np.array([[0], [0], [0], [1]])

    bp_and = BackPropagation(num_inputs=2, num_hidden_neurons=2, num_outputs=1,
                             learning_rate=0.1, activation_function='sigmoid', use_bias=True, random_seed=42)
    bp_and.train(X_and, y_and, num_epochs=10000, verbose=True)
    
    predictions_and = bp_and.predict(X_and)
    print("Previsões AND:")
    print(predictions_and)

    # OR
    X_or = np.array([[0, 0],
                     [0, 1],
                     [1, 0],
                     [1, 1]])
    y_or = np.array([[0], [1], [1], [1]])

    bp_or = BackPropagation(num_inputs=2, num_hidden_neurons=2, num_outputs=1,
                            learning_rate=0.1, activation_function='sigmoid', use_bias=True, random_seed=42)
    bp_or.train(X_or, y_or, num_epochs=10000, verbose=True)

    predictions_or = bp_or.predict(X_or)
    print("Previsões OR:")
    print(predictions_or)
