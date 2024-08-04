pipeline {

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Build') {
                agent {
                    dockerfile true
                }
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