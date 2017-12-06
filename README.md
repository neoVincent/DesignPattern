# DesignPattern
This is the repo for learning design pattern

## MVC
It is a Qt application where the icon will be highlighted with an animation when the button is clicked. Also the text bar beside the button indicates the current option. Combined with Qt framework, MVC design pattern is well carried out during the implemention. The following are 3 main parts of the project.

- *Model*. 
It keeps the state. Once the state is changed, it will send out signal, for example, the UI may update based on the state.

- *Processor*.
After installing customized event filter, it can listen to certain event and parse the event into state change request, for example LightOn. The worker thread of the Processor executes action based on this request. After that, update the state of model.

- *Monitor*.
It is UI which monitors the state changes in model so that it can update UI.

### Workflow
When the UI is intrigued, a certain event will be created and dispatched to the event loop. Since the processor has already installed the eventFilter, it can get its target events and parse the data in that. Then processor requests the worker thread to finish the task. After that, worker thread changes the state in stateModel, which leads to a  related signal to be sent in StateModel to inform UI or other processorComonent.