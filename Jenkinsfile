pipeline {
    agent {
        docker{

            filename 'Dockerfile'
        }
    }

    stages {

        stage('Build') {
            steps {
                sh 'gcc --version'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
}