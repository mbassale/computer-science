
device = torch.device('cuda' if torch.cuda.is_available() else 'mps' if torch.backends.mps.is_available() else 'cpu')
display(device)

RANDOM_SEED = 42
np.random.seed(RANDOM_SEED)
torch.manual_seed(RANDOM_SEED)

# Syntetic Data Generation
true_b = 1
true_w = 2
N = 100

x = np.random.rand(N, 1)
epsilon = (0.1 * np.random.randn(N, 1))
y = true_b + true_w * x + epsilon

# Shuffles the indices
idx = np.arange(N)
np.random.shuffle(idx)

# Training set 80%
train_idx = idx[:int(N*.8)]
# Test set 20%
test_idx = np.setdiff1d(idx, train_idx)

# Generates train and validation sets
x_train, y_train = x[train_idx], y[train_idx]
x_test, y_test = x[test_idx], y[test_idx]
train_data = TensorDataset(torch.from_numpy(x_train).float(), torch.from_numpy(y_train).float())
display(train_data[:5])

# Data Loader
train_loader = DataLoader(dataset=train_data, batch_size=16, shuffle=True)

# graph test data
plt.scatter(x[train_idx], y[train_idx], color='blue', s=5)
plt.scatter(x[test_idx], y[test_idx], color='red', s=5)
plt.legend(['Train Data', 'Test Data'])
plt.title('Training and Test Data')

x_train_tensor = torch.as_tensor(x_train, dtype=torch.float32, device=device)
y_train_tensor = torch.as_tensor(y_train, dtype=torch.float32, device=device)
