
N_EPOCHS = 200
losses = []
validation_losses = []
for epoch in range(N_EPOCHS):
    loss = mini_batch(device, train_loader, train_step_fn)
    losses.append(loss)
    
    # Validation
    with torch.no_grad():
        validation_loss = mini_batch(device, validation_loader, validation_step_fn)
        validation_losses.append(validation_loss)

    if epoch % 10 == 0:
        print(f'Epoch: {epoch}, Train Loss: {loss:.4f}, Validation Loss: {validation_loss:.4f}')
display(model.state_dict(), optimizer.state_dict())
