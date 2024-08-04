pipeline {

    agent {
        dockerfile true
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