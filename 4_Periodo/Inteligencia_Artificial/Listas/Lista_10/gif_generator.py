import os
import imageio.v3 as imageio
import numpy as np
import matplotlib.pyplot as plt

class GifLogger:
    def __init__(self, inputs, expected_outputs, perceptron_model, 
                 x_margin=1, y_margin=1, frames_per_second=2):
        """
        Inicializa o logger para gerar GIFs durante o treinamento do perceptron.

        :param inputs: Conjunto de dados de entrada
        :param expected_outputs: Saídas esperadas (rótulos)
        :param perceptron_model: Instância do perceptron
        :param x_margin: Margem extra no eixo X para visualização
        :param y_margin: Margem extra no eixo Y
        :param frames_per_second: Taxa de quadros por segundo para o GIF
        """
        self.inputs = inputs
        self.labels = expected_outputs
        self.perceptron = perceptron_model
        self.frames_folder = "frames"
        self.gif_folder = "gifs"
        self.saved_frame_paths = []
        self.fps = frames_per_second

        input_array = np.array(inputs)
        self.x_min = input_array[:, 0].min() - x_margin
        self.x_max = input_array[:, 0].max() + x_margin
        self.y_min = input_array[:, 1].min() - y_margin
        self.y_max = input_array[:, 1].max() + y_margin

        os.makedirs(self.frames_folder, exist_ok=True)
        os.makedirs(self.gif_folder, exist_ok=True)
    # __init__

    def save_frame(self, epoch):
        plt.figure(figsize=(8, 6))

        for i, point in enumerate(self.inputs):
            color = 'red' if self.labels[i] == 0 else 'blue'
            label = f'Class {self.labels[i]}' if i == 0 else ""
            plt.scatter(point[0], point[1], color=color, label=label)

        x_values = np.linspace(self.x_min, self.x_max, 100)

        if abs(self.perceptron.weights[1]) < 1e-6:
            x_constant = -self.perceptron.bias_weight / (self.perceptron.weights[0] if abs(self.perceptron.weights[0]) > 1e-6 else 1e-6)
            plt.axvline(x=x_constant, color='green', label='Decision Boundary')
        else:
            slope = -self.perceptron.weights[0] / self.perceptron.weights[1]
            intercept = -self.perceptron.bias_weight / self.perceptron.weights[1]
            y_values = slope * x_values + intercept
            plt.plot(x_values, y_values, label='Decision Boundary', color='green')

        plt.title(f'Epoch {epoch + 1}')
        plt.xlabel('x1')
        plt.ylabel('x2')
        plt.legend()
        plt.grid(True)

        plt.xlim(self.x_min, self.x_max)
        plt.ylim(self.y_min, self.y_max)

        frame_path = os.path.join(self.frames_folder, f"frame_{epoch}.png")
        plt.savefig(frame_path)
        plt.close()

        self.saved_frame_paths.append(frame_path)
    # save_frame

    def generate_gif(self, output_filename="perceptron_training.gif"):
        output_path = os.path.join(self.gif_folder, output_filename)
        images = [imageio.imread(frame) for frame in self.saved_frame_paths]
        imageio.mimsave(output_path, images, fps=self.fps)

        for frame in self.saved_frame_paths:
            os.remove(frame)
        if os.path.exists(self.frames_folder):
            os.rmdir(self.frames_folder)

        print(f"GIF saved as {output_path}")
    # generate_gif
# GifLogger