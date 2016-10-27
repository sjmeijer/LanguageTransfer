#ifndef APPLICATIONSTATEMACHINE_H
#define APPLICATIONSTATEMACHINE_H

#include "application/application.h"
#include "application/applicationhandler.h"
#include "statemachine.h"
#include "applicationstate.h"

class Application;
class ApplicationState;

class ApplicationStateMachine : public ApplicationHandler, public StateMachine<Application>
{

    Q_OBJECT

public:
    ApplicationStateMachine(
        Application* o);

    ApplicationState* getCurrentState() const;

public slots:    
    virtual void playListRequestFinished(QNetworkReply* reply);

    virtual void backButtonClicked();

    virtual void courseClicked(const QModelIndex& index);

    virtual void lessonClicked(const QModelIndex& index);

    virtual void notesButtonClicked(const QModelIndex& index);

    virtual void notesChanged();

    virtual void playButtonClicked();

    virtual void sliderMoved(int position);

    virtual void sliderReleased();

    virtual void trackDurationChanged(qint64 duration);

    virtual void trackPositionChanged(qint64 position);

};

#endif // APPLICATIONSTATEMACHINE_H
